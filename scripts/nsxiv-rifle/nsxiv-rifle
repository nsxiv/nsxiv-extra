#!/bin/sh

TMPDIR="${TMPDIR:-/tmp}"
tmp="$TMPDIR/nsxiv_rifle_$$"

is_img_extension() {
    grep -iE '\.(jpe?g|png|gif|svg|jxl|webp|tiff|heif|avif|ico|bmp|pam|pbm|ppm|tga|qoi|ff)$'
}

listfiles() {
    find -L "$1" -maxdepth 1 -type f -print |
        is_img_extension | sort | tee "$tmp"
}

open_img() {
    file="$1"; shift;
    # only go through listfiles() if the file has a valid img extension
    if echo "$file" | is_img_extension >/dev/null 2>&1; then
        trap 'rm -f $tmp' EXIT
        count="$(listfiles "///${file%/*}" | grep -nF "$file")"
    fi
    if [ -n "$count" ]; then
        nsxiv -i -n "${count%%:*}" "$@" -- < "$tmp"
    else
        # fallback incase file didn't have a valid extension, or we couldn't
        # find it inside the list
        nsxiv "$@" -- "$file"
    fi
}

uri2path() {
    python3 - "$@" <<'___HEREDOC'
from urllib.parse import unquote, urlparse
from sys import argv
for arg in argv[1:]:
    print(unquote(urlparse(arg).path))
___HEREDOC
}

[ "$1" = '--' ] && shift
case "$1" in
    "") echo "Usage: ${0##*/} PICTURES" >&2; exit 1 ;;
    /*) open_img "$1" ;;
    "~"/*) open_img "$HOME/${1#"~"/}" ;;
    file:///*) open_img "$(uri2path "$1")" ;;
    trash:///*)
        trash_dir="${XDG_DATA_HOME:-$HOME/.local/share}/Trash/files"
        open_img "${trash_dir}$(uri2path "$1")" -N "nsxiv_trash"
        ;;
    *) open_img "$PWD/$1" ;;
esac
