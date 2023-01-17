# nsxiv-open

This script tries to open every given file with nsxiv if possible. It will
generate thumbnails for videos and decrypt PGP-encrypted files. If the given
(or transformed) file cannot be opened with nsxiv, it asynchronously opens it
with `xdg-open`.

## Dependencies

- `xargs` with `-P` option ("max procs")

## Optional Dependencies

- `gpg`

## Security Issues

- Decrypted data are stored in plain files in the default directory of
  `mktemp`. If that directory is mounted as non-volatile, or if the kernel
  swaps the area holding the file in RAM to disk, the decrypted data may be
  temporarily written to persistent storage, possibly leaving traces.
- The decrypted plain files may be read by a local attacker between its
  generation and removal.
- The decrypted plain files may be passed to an unsafe program via `xdg-open`.

If you do not want nsxiv-open to decrypt or attempt to decrypt files, you can
set the environment variable `NSXIV_OPEN_NO_DECRYPT` to anything to disable it.

## Authors

- Berke Kocaoğlu <berke.kocaoglu@metu.edu.tr>
