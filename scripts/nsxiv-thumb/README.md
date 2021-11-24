# nsxiv-thumb

This script will generate thumbnails for each video file in the current directory
and present them via nsxiv in thumbnail mode. After nsxiv is closed, all marked
files will be opened sequentially with `xdg-open`.

As nsxiv does not retain the mark order, the files will be opened in sorted order
according to the current locale.

Dependencies:
- `ffmpegthumbnailer`
- `xdg-open`
- `sed` and `sort` with `-z` flag
- `xargs` with `-rnP0` flags
- `find` with `-mindepth`, `-maxdepth` and `-printf` flags

These are usually met on most modern Linux distributions. If your system is
strictly POSIX, this script will fail to work.

## Authors

* Berke Kocaoğlu <berke.kocaoglu@metu.edu.tr>
