## Managing customization and patches

nsxiv code-base aims to be simple and hack-able. User's are encouraged to edit
the source-code as they see fit. This includes simple customization in
`config.h` or more heavy customization via patches.

In order to manage such customization the best and recommended way is to use
`git`. Suckless's website has a [great guide](http://dwm.suckless.org/customisation/patches_in_git)
on how to use git branching and rebase to manage your personal build. If you're
unfamiliar with git then you may want to first familiarize yourself with some of
the basics first.
<!-- we should add some basic git guide here -->

## Hacking

The main method of customization is via editing [config.h](config.h), a plain
C99 header file. There are two ways you could edit this file.

The first is to change the values of the configuration variables. As an example,
the default value of the `ANTI_ALIAS` variable is `true`. You could set it to
`false` to start nsxiv without anti aliasing.

The second way is writing custom functions. In these functions, you may interact
with other components of nsxiv to implement macros, bindings or other
functionality. For instance, the following snippet calls the `run_key_handler`
function located in [main.c](main.c) to send the key handler a key with the
control modifier.

```c
static void run_key_handler(const char *, unsigned int);
bool cg_send_with_ctrl(arg_t key) {
    run_key_handler(XKeysymToString(key), ControlMask);
    return false;
}
```

You may then utilize this function to bind the `z` key to send `C-Kanji` to
the key handler:

```c
#define g_send_with_ctrl { cg_send_with_ctrl, MODE_ALL }
static const keymap_t keys[] = {
    ...
    { 0,            XK_z,             g_send_with_ctrl,     XK_Kanji },
    ...
}
```

For more complex functionality, you may also choose to directly edit the nsxiv
source; but, the above method of writing custom functions for `config.h` is
preferred as it can enable better compatibility between patches or with future
versions of nsxiv, and requires less maintenance by the user.

## Making your config forward compatible

If you want to only specify changes from the default in your config and make
your config forwards compatible then there's two ways to achieve that.

### Using a Diff/Patch

Instead of changing `config.h` directly you can store your changes in a .diff
and apply them on new updates.

### Using weak attributes

This is a more convoluted approach, but if you wish to follow this then the
steps are:

1. If you have a config.h rename it to config.c. You can and should remove any
   options you don't want to explicitly override
2. Generate a clean config.h (`make config.h`)
3. Run `sed -i "s/^static //g; s/ = / __attribute__((weak))&/g" config.h && sed -i "s/OBJS =/OBJS +=/g" Makefile`
4. Now run `OBJS=config.o make`

Any config option defined in `config.c` will override the defaults and if an
option is not specified, the default will be used. Any time you want to update
to the latest version, simply delete config.h and repeat steps 2-4.
