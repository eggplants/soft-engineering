#!/usr/bin/env bash

case "$(uname -o)" in
  "GNU/Linux" ) uri=JPjcs;;
  "Darwin" ) uri=JPjcw;;
  "Android" ) uri=JPjWH;;
  * ) exit 1;;
esac
curl -Lo popcat 'https://git.io/'"$uri"
sudo install -m+x popcat /usr/local/bin
