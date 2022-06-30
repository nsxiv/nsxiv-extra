# `dmenu` Imitation

Imitate [`dmenu`](https://tools.suckless.org/dmenu/):

```sh
"e")
    while IFS= read -r file; do
        echo "$file"
    done
    kill $PPID
    ;;
```

## Authors

* eylles <ed.ylles1997@gmail.com>
