Print images with [yad](https://github.com/v1cont/yad):

```sh
"p")
    while IFS= read -r file; do
        yad --print --type=image --filename="$file"
    done
    ;;
```
