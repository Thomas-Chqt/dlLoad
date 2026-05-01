#!/usr/bin/env bash
set -euo pipefail

SOURCE_DIR="${SOURCE_DIR:-/workspace}"
BUILD_DIR="${BUILD_DIR:-/build}"
BUILD_TYPE="${CMAKE_BUILD_TYPE:-Release}"
GENERATOR="${CMAKE_GENERATOR:-Ninja}"

parallelism() {
    nproc 2>/dev/null || getconf _NPROCESSORS_ONLN 2>/dev/null || echo 1
}

build_jobs="${CMAKE_BUILD_PARALLEL_LEVEL:-$(parallelism)}"
test_jobs="${CTEST_PARALLEL_LEVEL:-$(parallelism)}"

mkdir -p "${BUILD_DIR}"

cmake -S "${SOURCE_DIR}" -B "${BUILD_DIR}" \
    -G "${GENERATOR}" \
    -DCMAKE_BUILD_TYPE="${BUILD_TYPE}" \
    -DDL_BUILD_TESTS=ON \
    "$@"

cmake --build "${BUILD_DIR}" --parallel "${build_jobs}"
ctest --test-dir "${BUILD_DIR}" -j "${test_jobs}" --output-on-failure
