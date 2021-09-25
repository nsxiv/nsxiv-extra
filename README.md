# nsxiv-extra

This repo will be used for hosting community patches, user scripts, tips and
tricks etc. As of now, this is under construction, once we have everything
stabilized PRs will be opened.

- - -

## Community patches

| Name | Comments |
| :--  | :--      |

## User scripts

Here are some examples scripts which add new and commonly requested functionality to nsxiv:

| Name | Comments |
| :--  | :--      |
| [nsxiv-env](scripts/nsxiv-env) | Pass arguments to nsxiv using environment variables. |
| [nsxiv-url](scripts/nsxiv-url) | Open remote files. |
| [nsxiv-rifle](scripts/nsxiv-rifle) | Open all images in a directory. |

## Tips and Tricks

These are a couple small one liner tips and tricks which you can incorporate into your personal scripts.

* Randomize images for slideshow

```sh
find . -type f | shuf | nsxiv -i -S 2
```

## Build scripts

Here are some examples scripts which change the behavior of compilation/linkage:

| Name | Comments |
| :--  | :--      |
| [override-config](https://github.com/nsxiv/nsxiv/wiki/override-config) | Make your config forwards compatible |
