# env-theme

This patch adds the ability to change colors and font based on environment
variables.

Xresources takes priority, then env vars, then `config.h` defaults. Env names
defaults to: `NSXIV_BG`, `NSXIV_FG`, `NSXIV_MARK_COLOR`, `NSXIV_BAR_BG`,
`NSXIV_BAR_FB`, `NSXIV_FONT` and can be changed in `config.h`.

## Authors

* p-kolacz <piotr@kolacz.org>
