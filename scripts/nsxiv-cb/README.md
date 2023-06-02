# nsxiv-cb

This script uses `fuse-archive` to open image archives (i.e comic books such as
cbz, cbr etc) with `nsxiv`.

## Session support

`nsxiv-cb` also supports remembering the last position of a file and resuming
from there. To enable support for this feature, put the following line into your
`win-title` script:

```sh
[ -n "$NSXIV_CB_OUTPUT" ] && [ -n "$4" ] &&
	printf '%s\t%s\n' "$2" "$3" > "$NSXIV_CB_OUTPUT"
```

The session files will be saved inside `${XDG_DATA_HOME}/nsxiv-cb`.

## Dependencies

* [`fuse-archive`](https://github.com/google/fuse-archive)

If you want to use a different archive-mounter, then you can use the environment
variable `NSXIV_CB_MNT`.

## Authors

* GrimNight <grimnight@codeberg>
* NRK \<nrk AT disroot DOT org>
