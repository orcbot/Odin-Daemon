# Base image
FROM library/ubuntu:17.10

# Maintainer
MAINTAINER Compiax (Pty) Ltd. <admin@compiax.io>

# Updating repositories.
RUN \
  apt-get clean && \
  apt-get update

RUN apt-get install -y \
  g++ \
  cmake \
  libgtest-dev && \
rm -rf /var/lib/apt/lists/*

RUN \
  cd /usr/src/gtest && \
  cmake CMakeLists.txt && \
  make && \
  cp *.a /usr/lib

# Set Workdir
WORKDIR /opt/odin/daemon

# Expose ports
EXPOSE 8000

# Get source
COPY . .

# Entrypoint
ENTRYPOINT ["sh", "entrypoint.sh"]

# Command
CMD ["./Odin.out"]
