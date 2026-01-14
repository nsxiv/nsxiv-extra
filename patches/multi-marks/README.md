# multi-marks

This patch adds an optional argument to the `-o` flag.
Be advised that it will therefore break standard behaviour when using short
option chaining. (i.e the `t` in `nsxiv -ot` will be considered an argument to
`-o`; this can be fixed by using `nsxiv -o -t` instead).
If this argument is not given, the behaviour is the same as mainline nsxiv.

Otherwise, the argument is treated as a comma separated list of the form:
`file[:display]`. Pressing the `g_cycle_image_mark` keybinding (default:
<kbd>m</kbd>), will then cycle through the marks of the list, showing the
`display` part of the item instead of the `*` in the corner of the window.

For example, the cycle for `-o'foo,bar,baz'` is `no mark -> foo -> bar -> baz
-> no mark`.

If the `display` part is omitted, then the file is shown. Finally, when
exiting, the names of the marked images are not written to stdout, but instead
to the file associated with their mark.

Existing files are overwritten, unless the `--append` flag is supplied.

This allows the user to do several operations in "one pass" over the images,
for instance with a function like:

```
move_or_delete() {
	dest="$1"; shift
	mvfile=$(mktemp)
	rmfile=$(mktemp)

	nsxiv -o"${mvfile}:move,${rmfile}:remove" "$@"

	while read -r f; do
		mv "$f" "$dest"
	done < "$mvfile"

	while read -r f; do
		rm "$f"
	done < "$rmfile"

	rm "$rmfile" "$mvfile"
}
```

This patch also adds the `g_last_image_mark` command (default keybinding
<kbd>,</kbd>), which sets the mark of the current image to the mark of the last
marked image. For instance, if you have given `-o'foo,bar,baz'` and are on the
image *n* in

```
+-------+-------+---------+---------+
| n - 3 | n - 2 | n - 1   | n       |
+-------+-------+---------+---------+
| foo   | bar   | no mark | no mark |
+-------+-------+---------+---------+
```

then the `g_last_image_mark` command will set the image to `bar`.
