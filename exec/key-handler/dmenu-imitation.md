# `dmenu` Imitation

Imitate [`dmenu`](https://tools.suckless.org/dmenu/):

```sh
"e")
    while IFS= read -r file; do
        printf "%s\n" "$file"
    done
    kill $PPID
    ;;
```

## Authors

* eylles <ed.ylles1997@gmail.com>
* NRK \<nrk at disroot dot org>
* Berke Kocaoğlu <berke.kocaoglu@metu.edu.tr>
