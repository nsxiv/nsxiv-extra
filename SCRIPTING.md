# Scripting

These are a couple small one liner tips and tricks which you can incorporate
into your personal scripts.

* Randomize images for slideshow

```sh
find . -type f | shuf | nsxiv -i -S 2
```

* [KEYHANDLER]: dmenu imitation

```sh
"e") # dmenu imitation
while IFS= read -r file; do
	echo "$file"
done
kill $PPID
;;
```

* [KEYHANDLER]: printing images with [yad](https://github.com/v1cont/yad)

```sh
"p")  while IFS= read -r file; do yad --print --type=image --filename="$file" ; done ;;
```

* [KEYHANDLER]: detecting the resource name for nsxiv's window:

```sh
if xprop -id "$(xdo id -p $PPID)" | grep 'WM_CLASS.*subtube' >/dev/null 2>&1; then
  subtube_active=1
fi
```

This will set the variable `subtube_active` to `1` if the `WM_CLASS` atom of
nsxiv has "subtube" in it. You can write conditionals around this to have
certain keybindings active only when nsxiv's window has certain `WM_CLASS` set.
