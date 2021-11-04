# nsxiv-pipe

This script allows piping images into `nsxiv` via draining the pipe into a temp
file. `$TMPDIR` is respected if set. Example usage:

```sh
curl 'https://link.to/image' | nsxiv-pipe

nsxiv-pipe <(cat image)
```

# Authors

* mamg22 <marcomonizg@gmail.com>
* NRK \<nrk at disroot dot org>
