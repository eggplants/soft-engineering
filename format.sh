#!/usr/bin/env bash

find "$(dirname $0)" -name "*.c" -type f |
  while read -r i; do
    echo "[$i]"
    clang-format -i "$i"
    echo -ne '\e[F\e[J'
  done
  echo "[done!]"
