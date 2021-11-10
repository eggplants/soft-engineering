#!/usr/bin/env bash

find "$(dirname $0)" -name "*.c" -type f |
  while read -r i; do
    echo "[$i]"
    clang-format -i "$i"
    echo -ne '\033[F\033[J'
  done
  echo "[done!]"
