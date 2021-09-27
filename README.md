# nsxiv-extra

This repo will be used for hosting community patches, user scripts, tips and
tricks etc. ***As of now, this is under construction, once we have everything
stabilized PRs will be opened.***

For info on how to use nsxiv, please read the manpage.

    $ man nsxiv

For info on how to manage patches and customization, please see [managing
customization and patches](CUSTOMIZATION.md)

- - -

## Community patches

| Name | Comments |
| :--  | :--      |
| [dmenu-mode](patches/dmenu-mode) | Add dmenu mode to nsxiv |
| [image-mode-cycle](patches/image-mode-cycle) | Cycle when viewing multiple images |

## User scripts

Some examples scripts which add new and commonly requested functionality to
nsxiv. These are meant to be minimal examples, users are encouraged to modify
them to fit their use-cases.

| Name | Comments |
| :--  | :--      |
| [nsxiv-env](scripts/nsxiv-env) | Pass arguments to nsxiv using environment variables. |
| [nsxiv-url](scripts/nsxiv-url) | Open remote files. |
| [nsxiv-rifle](scripts/nsxiv-rifle) | Open all images in a directory. |
| [nsxiv-saver](scripts/nsxiv-saver) | Use nsxiv as a xsecurelock screensaver. |

## Tips and Tricks

These are a couple small one liner tips and tricks which you can incorporate into your personal scripts.

* Randomize images for slideshow

```sh
find . -type f | shuf | nsxiv -i -S 2
```
