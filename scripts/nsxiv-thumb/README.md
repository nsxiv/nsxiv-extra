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
- `sha512sum`
- `stat` with `-f` flag

You can change what to open the files with by setting the `OPENER` variable in
the beginning of both scripts. Default is `$OPENER` or `xdg-open`.

## Authors

* Berke Kocaoğlu <berke.kocaoglu@metu.edu.tr>
