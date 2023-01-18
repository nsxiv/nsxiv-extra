# nsxiv-fill

This script launches `nsxiv` so that the window size is set to the image size.

The `WM_CLASS` of nsxiv is set to "nsxiv-fill". If you are using a tiling window
manager, add a rule to make this a floating window. For example, in `dwm` the
following (in `config.h`) will do the job:

```c
static const Rule rules[] = {
	/* class          instance      title       tags mask     isfloating   monitor */
	{ NULL,         "nsxiv-fill",   NULL,       0,            1,           -1 },
```

Consult your WM's docs if you're using something else.

## Dependencies

* `imlib2_load` to grab the image dimensions. This was chosen simply because
  `nsxiv` depends on `imlib2` already, so you most likely have it installed on
  your system. But it should be trivially possible to replace it with something
  else.

## Possible Improvements

The script disables the status-bar (via the `-b` flag) so that the status-bar
doesn't overlap on top of the image. If the status-bar font size is [set in
pixels][px] then it should be possible to account for the bar-height and adjust
the height of the window accordingly.

[px]: https://codeberg.org/nsxiv/nsxiv-record/issues/246#issuecomment-475710

## Authors

* NRK \<nrk at disroot dot org>
