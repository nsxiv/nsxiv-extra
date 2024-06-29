# Appstream metainfo

This is a metadata file that will make the nsxiv package show up in gnome software, kde discover and other appstream compatible software centers/stores when included as part of the package as done in the [solus nsxiv package](https://github.com/getsolus/packages/tree/main/packages/n/nsxiv)

the metadata file alone is [page.codeberg.nsxiv.nsxiv.metainfo.xml](page.codeberg.nsxiv.nsxiv.metainfo.xml)

there are 3 patches provided:

| Name | Comments |
| :--  | :--      |
| [full](full.patch) | full patch for the makefile to add the `install-metainfo` target along the metainfo file in create mode, perfect to use in a debian style build patch series. |
| [makefile](makefile.patch) | patch only the makefile, if you want to add the file manually to your build and just patch the makefile. |
| [metainfo file](metainfo.patch) | create mode diff to add the metainfo only to the git vcs, added for completeness sake. |
