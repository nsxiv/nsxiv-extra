# nsxiv-env

This script will run `nsxiv` using arguments extracted from the environment
variables `NSXIV_OPTS`. CLI arguments takes priority over `NSXIV_OPTS`.

You can edit `NSXIV_OPTS` in the script or export `NSXIV_OPTS` in your shell
profile (e.g `~/.bash_profile` or `~/.zprofile`) to change the default
arguments passed to nsxiv.

One thing to note is that if you rename this script to `nsxiv` and put in in
your `PATH` before `nsxiv` (the actual binary) you will have to use the entire
path to call `nsxiv`, otherwise the script will go into an infinite recursion.

```diff
-exec nsxiv $NSXIV_OPTS "$@"
+exec /path/to/nsxiv $NSXIV_OPTS "$@"
```

## Authors

* Arthur Williams <taaparthur@gmail.com>
* NRK \<nrk at disroot dot org>
* Berke Kocaoğlu <berke.kocaoglu@metu.edu.tr>
* eylles <ed.ylles1997@gmail.com>
