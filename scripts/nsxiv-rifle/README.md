# nsxiv-rifle

This is a modified and more performant version of the
[sxiv-rifle](https://github.com/ranger/ranger/blob/master/examples/rifle_sxiv.sh) script.
This script opens an image as well as all the other images in that directory.

One thing to note here is that `-maxdepth` is not posix, so it may not be available
on your version of `find` if you're on a non-GNU system. Please make the following
changes if `-maxdepth` is not available for you. This may cause slight performance
decrease.

```diff
-    find -L "///${1%/*}" -maxdepth 1 -type f -print |
+    find -L "///${1%/*}" \( ! -path "///${1%/*}" -prune \) -type f -print |
```

## Authors

* Original `sxiv-rifle` authors
* NRK <nrk at disroot dot org>
