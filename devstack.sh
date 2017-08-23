#!/usr/bin/env sh

docker build -t compiax/odin-daemon:source-latest .

docker run \
  -it \
  --rm \
  --name "odin-daemon" \
  -p 8000:8000 \
  compiax/odin-daemon:source-latest
