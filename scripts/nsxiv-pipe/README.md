# nsxiv-pipe

This script allows piping images into `nsxiv` via draining the pipe into a temp
file. The reason for this is because `Imlib2` (the image library nsxiv uses)
cannot read from pipes
([#296](https://codeberg.org/nsxiv/nsxiv/issues/296)).
`$TMPDIR` is respected if set.

Example usage:

```sh
curl 'https://link.to/image' | nsxiv-pipe

nsxiv-pipe < /path/to/image.png
```

# Authors

* mamg22 <marcomonizg@gmail.com>
* NRK \<nrk at disroot dot org>
