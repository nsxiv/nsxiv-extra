# Managing customization and patches

nsxiv code-base aims to be simple and hack-able. User's are encouraged to edit
the source-code as they see fit. This includes simple customization in
`config.h` or more heavy customization via patches.

In order to manage such customization the best and recommended way is to use
`git`. Suckless's website has a [great guide](http://dwm.suckless.org/customisation/patches_in_git)
on how to use git branching and rebase to manage your personal build. If you're
unfamiliar with git then you may want to first familiarize yourself with some of
the basics first.
<!-- we should add some basic git guide here -->


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
