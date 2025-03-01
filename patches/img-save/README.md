# img-save

This patch adds the command `i_save`, that writes the current rendered view
of the image as a new file with suffix `_nsxiv.${extension}`.
To add the keyboard shortcut, edit `config.h`:

```
    { ControlMask,  XK_s,             i_save,               None },
```

## Authors

* lucas mior \<lucas.mior at tutamail dot com>
