FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive
ENV CC=gcc
ENV CXX=g++

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
        build-essential \
        ca-certificates \
        cmake \
        git \
        ninja-build \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /workspace
VOLUME ["/build"]

COPY --chmod=755 docker/docker-entrypoint.sh /usr/local/bin/dlLoad-entrypoint

ENTRYPOINT ["/usr/local/bin/dlLoad-entrypoint"]
