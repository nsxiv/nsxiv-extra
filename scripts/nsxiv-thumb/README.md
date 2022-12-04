# nsxiv-thumb

This script will generate thumbnails for each video file in the current directory
and present them via nsxiv in thumbnail mode. After nsxiv is closed, all marked
files will be opened sequentially with the specified opener.

As nsxiv does not retain the mark order, the files will be opened in sorted order
according to the current locale.

Atypical dependencies for the Linux version are:
- `ffmpegthumbnailer`

Dependencies not specified by POSIX for the \*BSD version are:
- `ffmpegthumbnailer`
- `file` with `-b` and `--mime-type` flags
- `md5`
- `stat` with `-f` flag

You can change what to open the files with by setting the `OPENER` variable in
the beginning of both scripts. Default is `$OPENER` or `xdg-open`. Execute the
script like `OPENER=echo nsxiv-thumb` to use it as a filter. Beware that
`$OPENER` is `eval`ed.

## Examples

In this section, you *may not* blindly swap `nsxiv-thumb` and `nsxiv-thumb-bsd`
and expect the example to function the same.

### Usage with [lf](https://github.com/gokcehan/lf)

Here we embed `nsxiv` in our `tabbed` instance with X ID `$TABBED_XID`, and set
`OPENER` to `printf "%s\0"` to use `nsxiv-thumb` as a filter with
null-delimited output. After `nsxiv` halts, the marked files are selected in
`lf`.

```sh
cmd selectnsxivthumb %{{
    OPENER='printf "%s\0"' SIZE=768 nsxiv-thumb -e "$TABBED_XID" | xargs -r0 realpath -sm -- | while IFS= read -r i; do
        lf -remote "send $id select '$i'" && lf -remote "send $id toggle"
    done
    lf -remote "send $id select '$f'"
}}
```

## Authors

* Berke Kocaoğlu <berke.kocaoglu@metu.edu.tr>
