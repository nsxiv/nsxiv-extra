# Appstream metainfo

This is a metadata file that will make the nsxiv package show up in gnome software, kde discover and other appstream compatible software centers/stores when included as part of the package as done in the [solus nsxiv package](https://github.com/getsolus/packages/tree/main/packages/n/nsxiv).

The metadata file alone is [page.codeberg.nsxiv.nsxiv.metainfo.xml](page.codeberg.nsxiv.nsxiv.metainfo.xml).
The `Makefile` provides `{install,uninstall}-metainfo` targets for installing and uninstalling the appstream xml file.
