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
