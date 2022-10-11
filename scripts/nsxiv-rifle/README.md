# nsxiv-rifle

This is a modified version of the [sxiv-rifle][] script.
This script opens an image as well as all the other images in that directory.

One thing to note here is that `-maxdepth` is not POSIX, so it may not be
available on your version of `find` if you're on a non-GNU system.
Please make the following changes if `-maxdepth` is not available for you.
This may cause slight performance decrease.

```diff
-    find -L "///${1%/*}" -maxdepth 1 -type f -print |
+    find -L "///${1%/*}" \( ! -path "///${1%/*}" -prune \) -type f -print |
```

[sxiv-rifle]: https://github.com/ranger/ranger/blob/master/examples/rifle_sxiv.sh

### Sorting

By default, `nsxiv-rifle` will sort the files alphabetically.
Following are a couple more methods of sorting:

* Natural sort (requires GNU sort)

```diff
-        is_img_extension | sort | tee "$tmp"
+        is_img_extension | sort -V | tee "$tmp"
```

* Sort by modification time (requires `stat`)

```diff
-    find -L "///${1%/*}" -maxdepth 1 -type f -print |
-        is_img_extension | sort | tee "$tmp"
+    find -L "///${1%/*}" -maxdepth 1 -type f -exec stat -c '%Y %n' {} + |
+        sort -nr | cut -d' ' -f 2- | is_img_extension | tee "$tmp"
```

### URI

`nsxiv-rifle` can also handle `file://` and `trash://` URIs.
`WM_CLASS` will be be set to `nsxiv_trash` when opening trash URI.
You may wish to change your `key-handler` bindings [when browsing trash
images][atom] as it can be used for restoring or permanently deleting the images
via using an [xdg compliant tool for trash management][trash].

An in-lined python3 script `uri2path` is used for URI decoding, if you don't
want a python dependency you may use [this][awk] awk script instead.

[atom]: ../../exec/key-handler/atom-detection.md
[trash]: https://wiki.archlinux.org/title/Trash_management
[awk]: https://github.com/stroborobo/werc/blob/master/bin/contrib/urldecode.awk

<details>
<summary>awk uri2path</summary>

```sh
uri2path () {
  printf '%s' "${1#*://}" | awk '
  BEGIN {
    hextab ["0"] = 0; hextab ["8"] = 8;
    hextab ["1"] = 1; hextab ["9"] = 9;
    hextab ["2"] = 2; hextab ["A"] = hextab ["a"] = 10
    hextab ["3"] = 3; hextab ["B"] = hextab ["b"] = 11;
    hextab ["4"] = 4; hextab ["C"] = hextab ["c"] = 12;
    hextab ["5"] = 5; hextab ["D"] = hextab ["d"] = 13;
    hextab ["6"] = 6; hextab ["E"] = hextab ["e"] = 14;
    hextab ["7"] = 7; hextab ["F"] = hextab ["f"] = 15;
  }
  {
    decoded = ""
    i   = 1
    len = length ($0)
    while ( i <= len ) {
      c = substr ($0, i, 1)
      if ( c == "%" ) {
        if ( i+2 <= len ) {
          c1 = substr ($0, i+1, 1)
          c2 = substr ($0, i+2, 1)
          if ( hextab [c1] == "" || hextab [c2] == "" ) {
            print "WARNING: invalid hex encoding: %" c1 c2 | "cat >&2"
          } else {
            code = 0 + hextab [c1] * 16 + hextab [c2] + 0
            c = sprintf ("%c", code)
            i = i + 2
          }
        } else {
          print "WARNING: invalid % encoding: " substr ($0, i, len - i)
        }
      } else if ( c == "+" ) {
        c = " "
      }
      decoded = decoded c
      ++i
    }
  print decoded
  }'
}
```
</details>

## Authors

* Original `sxiv-rifle` authors
* NRK \<nrk at disroot dot org>
* eylles <ed.ylles1997@gmail.com>
* Berke Kocaoğlu <berke.kocaoglu@metu.edu.tr>
