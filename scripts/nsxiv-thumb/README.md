# nsxiv-thumb

This script will generate thumbnails for each video file in the current directory
and present them via nsxiv in thumbnail mode. After nsxiv is closed, all marked
files will be opened sequentially with `xdg-open`.

As nsxiv does not retain the mark order, the files will be opened in sorted order
according to the current locale.

Dependencies for non-POSIX version:
- `ffmpegthumbnailer`
- `xdg-open`
- `sed` and `sort` with `-z` flag
- `xargs` with `-rnP0` flags
- `find` with `-mindepth`, `-maxdepth` and `-printf` flags

Dependencies for POSIX version:
- `ffmpegthumbnailer`
- `xdg-open`

It is advisable to use the non-POSIX version if your system satisfies all of the
dependencies as it supports arbitrary file paths (including characters like
`\n`, `\r`, etc.) and should perform much better.

## Authors

* Berke Kocaoğlu <berke.kocaoglu@metu.edu.tr>
