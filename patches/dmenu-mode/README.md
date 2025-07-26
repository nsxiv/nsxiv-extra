# dmenu-mode

This patch adds `-O` flag which will print the filename of an image as soon as
it's marked. Note that images cannot be unmarked in this mode. Reverse marking
(<kbd>Ctrl\-m</kbd>) is also disabled.

Older version of the patch also used to add a <kbd>Shift+Enter</kbd> keybinding
which will print the current filename to stdout and exit.
This has since been merged into mainline nsxiv
(https://codeberg.org/nsxiv/nsxiv/pulls/432) and thus no longer needed here.

Note: you can use `git am -i <patch>` to interactively pick which patch to
apply for the older versions.

## Authors

* NRK \<nrk at disroot dot org>
* Lucas Mior \<lucas.mior at tutamail dot com>
