const express = require("express");
const bodyParser = require("body-parser");
const mongoose = require("mongoose");
const _ = require("lodash");

//const date = require(__dirname + "/date.js");


const app = express();

app.set('view engine', "ejs");


app.use(bodyParser.urlencoded({ extended: true }));
app.use(express.static("public"));

mongoose.connect('mongodb://localhost:27017/toDoListDB');



//home items schema
const itemsSchema = {
    name: String
}

const Item = mongoose.model("Item", itemsSchema);


const item1 = new Item({
    name: "Welcome to your to do list."
});
const item2 = new Item({
    name: "Hit the + button to add a new item."
});
const item3 = new Item({
    name: "<~~ Hit this to delete an item."
});

const defaultItems = [item1, item2, item3];

//list schema

const listSchema = {
    name: String,
    items: [itemsSchema]
}

const List = mongoose.model("List", listSchema);


//home
app.get('/', function(req, res) {
    //const day = date.getDate();


    Item.find({}, function(err, results) {
        if (results.length === 0) {
            Item.insertMany(defaultItems, function(err) {
                if (err) {
                    console.log(err);
                } else {
                    console.log("Successfully inserted default items into collection, items");
                }
            });
            res.redirect("/");

        } else {
            res.render("list", { listTitle: "Today", newListItems: results });
        }
    });




});

// dynamic route
app.get('/:postName', function(req, res) {
    const requestedName = _.toLower(req.params.postName);

    List.findOne({ name: requestedName }, function(err, foundList) {
        if (!err) {
            if (!foundList) {
                //create a new list
                const list = new List({
                    name: requestedName,
                    items: defaultItems
                });
                list.save();
                res.redirect("/" + requestedName);
                console.log("Not Found, creating new..");

            } else {
                //show an existing list.
                res.render("list", { listTitle: foundList.name, newListItems: foundList.items });
                console.log("Found. opening...");
            }

        }

    });



})

app.post('/', function(req, res) {
    const itemName = req.body.newItem;

    const newItem = new Item({
        name: itemName
    });

    newItem.save(function(err) {
        if (err) {
            console.log(err);
        } else {
            console.log("New item added");
            res.redirect("/");
        }
    });


});

app.post('/delete', function(req, res) {
    const checkedItemId = req.body.checkbox;
    Item.findByIdAndRemove(checkedItemId, function(err) {
        if (err) {
            console.log(err);
        } else {
            console.log("Successfully deleted the item");
            res.redirect("/");
        }
    })
});

app.post('/:postName', function(req, res) {
    const listName = req.body.newItem;
    res.redirect("/:postName");
});

//about
app.get("/about", function(req, res) {
    res.render("about");
})


app.listen(3000, function(req, res) {
    console.log("Server is running on port 3000");
});