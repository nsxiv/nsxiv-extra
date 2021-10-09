# nsxiv-extra

This repo will be used for hosting community patches, user scripts, tips and
tricks etc.

For info on how to use nsxiv, please read the manpage.

    $ man nsxiv

For info on how to manage patches and customization, please see
[CUSTOMIZATION](CUSTOMIZATION.md)

- - -

## Community patches

| Name | Comments |
| :--  | :--      |
| [dmenu-mode](patches/dmenu-mode) | Add dmenu mode to nsxiv |
| [image-mode-cycle](patches/image-mode-cycle) | Cycle when viewing multiple images |

For submitting patches please use the following format:

* patchname-[BASE].ext

`patchname` is simply the name of the patch and `.ext` is the extension, which
can be either `.diff` or `.patch`. ` [BASE]` corresponds to either the version
or the seven chars git commit short hash corresponding to the last commit on
which the patch can be applied correctly and is working with.

Feel free you add yourself to the list of "Authors" if you contribute to a
patch. Adding some form of contact detail is also encouraged. See
[#Issues](#Issues) for more details.

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

## Tips and Tricks

These are a couple small one liner tips and tricks which you can incorporate
into your personal scripts.

* Randomize images for slideshow

```sh
find . -type f | shuf | nsxiv -i -S 2
```

* [KEYHANDLER]: dmenu imitation

```sh
"e") # dmenu imitation
while read file; do
	echo "$file"
done
kill $PPID
;;
```

* [KEYHANDLER]: printing images with [yad](https://github.com/v1cont/yad)

```sh
"p")  while read file; do yad --print --type=image --filename="$file" ; done ;;
```

## Issues

Since this repo is community maintained the github issue tracker is disabled. If
you run into any problems with any of the patches/scripts, try to fix it
yourself and submit a pull request. If you're unable to do so, then you may
contact the patch author if contact info has been provided.

For patch submitter and contributors, it's encouraged (but not required) to provide some sort of
contact info so that users can send bug reports (or gratitude :)). The
*preferred* contact method should be an email, however you're free to submit
whatever you'd like.
