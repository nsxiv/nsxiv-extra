# nsxiv-extra

This repo is be used for hosting community patches, user scripts, tips and
tricks, etc.

* For information on nsxiv, please consult the
  [nsxiv readme](https://github.com/nsxiv/nsxiv).
* For information on how to manage patches and customization, please see
  [CUSTOMIZATION](CUSTOMIZATION.md).
* For general tips and tricks on scripting with nsxiv, please see
  [SCRIPTING](SCRIPTING.md).

- - -

Feel free to add yourself to the list of "Authors" if you contribute to
anything. You may also add some form of contact detail if you wish
(preferably email, but can be anything else).

NOTE: All patches and scripts in this repository are community submitted and
maintained. Mainline nsxiv does not make any guarantee that there won't be
merge conflicts or broken functionality on upgrade.

## Community patches

| Name | Comments |
| :--  | :--      |
| [alpha](patches/alpha) | Add alpha/transparency to nsxiv |
| [dmenu-mode](patches/dmenu-mode) | Add dmenu mode to nsxiv |
| [image-mode-cycle](patches/image-mode-cycle) | Cycle when viewing multiple images |
| [toggle-winbg](patches/toggle-winbg) | Keybinding to toggle the window background color |
| [zoom-per-image](patches/zoom-per-image) | Remember what the zoom for image was |

For patch submissions please use the following format:

* name-[BASE].ext

`name` is simply the name of the patch and `.ext` is the extension, which
can be either `.diff` or `.patch`. `[BASE]` corresponds to either the version
or the seven chars git commit short hash corresponding to the last commit on
which the patch can be applied correctly and is tested to work with.

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
| [subtube](https://github.com/nagy135/subtube) | Watch subscribed youtubed videos. |
| [nsxiv-pipe](scripts/nsxiv-pipe) | Pipe images into nsxiv |
| [nsxiv-thumb](scripts/nsxiv-thumb) | Select videos to open in the current directory. |

For script submissions, it is highly encouraged (but not required) to use POSIX
`sh` rather than `bash`, `zsh`, `Python`, etc.

## Issues

Since this repo is community maintained there's no guarantee that an issue will
be worked on. If you run into any problems with any of the patches/scripts, try to
fix it yourself and submit a pull request.

You may also open an issue for a request, but as stated above, there's no guarantee.
