# cb\_mode

This patch adds a flag `-C` and `--cb_mode` to print file index + 1, file count and filename,
+separated by tabs on exit. Prevents `-o` and `--stdout` from working..

# nsxiv-cb

This script uses `fuse-archive` to open image archives with `nsxiv`.
This script saves session files in `${XDG_DATA_HOME}/nsxiv-cb`.

## Dependencies

* `fuse-archive` from [google/fuse-archive].
* `md5sum`.
* `cb_mode` patch.

[google/fuse-archive]: https://github.com/google/fuse-archive

## Authors

* GrimNight <grimnight@codeberg>
