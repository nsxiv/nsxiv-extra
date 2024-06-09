# nsxiv-pipe

This script allows piping images into `nsxiv` via draining the pipe into a temp
file. The temporary file will be automatically cleaned up on exit.
`$TMPDIR` is respected if set.

Example usage:

```console
$ curl 'https://link.to/image' | nsxiv-pipe
$ nsxiv-pipe < /path/to/image.png
```

## zsh users

For zsh users, `nsxiv-pipe` is pretty pointless because zsh supports creating
tmpfiles via process substitution. Examples using
[sxot](https://codeberg.org/NRK/sxot) to take screenshot and
[curl](https://curl.se) to download an image:

```console
$ nsxiv =(sxot)
$ nsxiv =(curl 'https://codeberg.org/nsxiv/pages/raw/branch/master/img/logo.png')
$ nsxiv =(sxot) =(curl ...)    # works for multiple pipes too
```

Bash and many other shells do not have any such feature.
Which is what `nsxiv-pipe` is supposed to tackle.

# Authors

* mamg22
* NRK \<nrk at disroot dot org>
