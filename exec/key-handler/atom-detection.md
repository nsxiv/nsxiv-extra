This will set the variable `subtube_active` to `1` if the `WM_CLASS` atom of
nsxiv has "subtube" in it. You can write conditionals around this to have
certain keybindings active only when nsxiv's window has certain `WM_CLASS` set.

```sh
if xprop -id "$(xdo id -p $PPID)" WM_CLASS | grep -Fq 'subtube'; then
    subtube_active=1
fi
```
