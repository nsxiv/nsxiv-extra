```sh
"e")
    while IFS= read -r file; do
        echo "$file"
    done
    kill $PPID
    ;;
```
