# Print With `yad`

Print images with [yad](https://github.com/v1cont/yad):

```sh
"p")
    while IFS= read -r file; do
        yad --print --type=image --filename="$file"
    done
    ;;
```

## Authors

* eylles <ed.ylles1997@gmail.com>
