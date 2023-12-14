const express = require("express");
const bodyParser = require("body-parser");
const mongoose = require("mongoose");
const _ = require("lodash");

const date = require(__dirname + "/date.js");


const app = express();

app.set('view engine', "ejs");


app.use(bodyParser.urlencoded({ extended: true }));
app.use(express.static("public"));

mongoose.connect('mongodb+srv://admin-valiantlynx:valiantlynx@cluster0.lujhkmj.mongodb.net/toDoListDB');



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
    const day = date.getDate();


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
            res.render("list", { listTitle: day, newListItems: results });
        }
    });




});

// dynamic route
app.get('/:postName', function(req, res) {
    const requestedName = _.capitalize(req.params.postName);

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
                console.log("Not Found page, creating new..");

            } else {
                //show an existing list.
                res.render("list", { listTitle: foundList.name, newListItems: foundList.items });
                console.log("Found page. opening...");
            }

        }

    });



})

app.post('/', function(req, res) {
    const itemName = req.body.newItem;
    const listName = req.body.list;

    const item = new Item({
        name: itemName
    });


    if (listName === date.getDate()) {
        item.save();
        res.redirect("/");
    } else {
        List.findOne({ name: listName }, function(err, foundList) {
            foundList.items.push(item);
            foundList.save();
            res.redirect("/" + listName);
        });
    }


});

app.post('/delete', function(req, res) {
    const checkedItemId = req.body.checkbox;
    const listName = req.body.listDelete;

    if (listName === date.getDate()) {
        Item.findByIdAndRemove(checkedItemId, function(err) {
            if (err) {
                console.log(err);
            } else {
                console.log("Successfully deleted the item from /Root");
                res.redirect("/");
            }
        })
    } else {
        List.findOneAndUpdate({ name: listName }, { $pull: { items: { _id: checkedItemId } } }, function(err, foundItem) {
            if (!err) {
                console.log("Successfully deleted the item from /" + listName);
                res.redirect("/" + listName);
            }

        });
    }



});

app.post('/:postName', function(req, res) {
    const listName = req.body.newItem;
    res.redirect("/:postName");
});

//about
app.get("/about", function(req, res) {
    res.render("about");
})


let port = process.env.PORT;
if (port == null || port == "") {
    port = 3000;
}

app.listen(port, function(req, res) {
    console.log("Server is running successfully");
});
