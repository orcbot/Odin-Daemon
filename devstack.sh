#!/bin/sh

docker build -t odin/daemon:source-latest .

docker run \
  -it \
  --rm \
  -p 8000:8000 \
  odin/daemon:source-latest
