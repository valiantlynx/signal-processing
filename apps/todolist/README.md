# todolist
a to do list using ejs

its dynamic

website: https://valiantlynx.herokuapp.com/

### adding new projects with their own git history
```sh
git subtree add --prefix=apps/todolist https://github.com/valiantlynx/todolist.git master --squash
git subtree pull --prefix=apps/todolist https://github.com/valiantlynx/todolist.git master --squash
git subtree push --prefix=apps/todolist https://github.com/valiantlynx/todolist.git master

```

