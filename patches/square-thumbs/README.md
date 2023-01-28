# square-thumbs

This patch adds keybinding <kbd>s</kbd> in thumbnail mode to toggle between
usual thumbnails and squared ones.

Only in **thumbnail mode**; displays the images in squares of the same
size, in a more consitent and uniform way. It will scale into ('zoom')
the image if it happens to be too small (horizontally or vertically)
in a case that will leave a spaces around, which is the normal
behaviour.

Additionally adds a keybinding to change this at runtime and a
configuration option in config.def.h to change this at compile time.

## Authors

* explosion-mental
