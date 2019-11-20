#!/bin/bash

set -ex

cmake -H. -B_builds  -DBUILD_COVERAGE=ON
cmake --build _builds
cmake --build _builds --target test
cmake --build _builds --target gcov
gcovr -r  .
