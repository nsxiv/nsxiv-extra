# Image cropping

Crops 1% of the image via imagemagick.

* Ctrl+' - crops the image along the bottom edge by 1%.

* Ctrl+; - crops the image along the right edge by 1%.

* Mod+' - crops the image along the top edge by 1%.

* Mod+; - crops the image along the left edge by 1%.

```sh
crop() {
    while IFS= read -r file; do
        realpath -- "$file"
    done | sort | uniq | while IFS= read -r file; do
        convert "$file" -crop "$1" +repage "$file"
    done
}

"C-apostrophe")  crop "-0-99%" ;;
"C-semicolon")   crop "-99%-0" ;;
"M-apostrophe")  crop "+0+99%" ;;
"M-semicolon")   crop "+99%+0" ;;
```

## Authors

- Vasiliy Stelmachenok (ventureo@yandex.ru)
