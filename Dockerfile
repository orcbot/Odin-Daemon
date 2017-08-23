# To build use:
# docker build -t orian/cppenv:v1 .
FROM ubuntu:17.10
MAINTAINER Compiax (Pty) Ltd. <admin@compiax.io>

LABEL description="Odin-Daemon."

# Install dependencies
RUN apt-get update

RUN apt-get -y install g++ cmake git subversion

# Set Workdir
WORKDIR /home/odin/daemon

# Expose ports
EXPOSE 8000

# Get source
COPY . .

RUN cmake . && make Odin.out

CMD ["./Odin.out"]
