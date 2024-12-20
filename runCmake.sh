#!/bin/sh
parent_path=$( cd "$(dirname "${BASH_SOURCE[0]}")" ; pwd -P )
# Move into this script's directory, work with relative paths afterwards
cd "${parent_path}"

echo "Running Cmake from bash script..."

# Specify the source (-S) as well as the build (-B) folder, and the compiler meant to be used
# See https://cmake.org/cmake/help/latest/manual/cmake.1.html#manual:cmake(1) for more options
cmake -S src/ -B build/ -G "Visual Studio 17 2022"

echo "Done!"
