#!/bin/sh

# The root path of our repository
parent_path=$( cd "$(dirname "${BASH_SOURCE[0]}")" ; pwd -P )

# Move into this script's directory, work with relative paths afterwards
cd "${parent_path}"

# Run the formatter on all .cpp and .h files
find . -regex '.*\.\(cpp\|h\)' -exec clang-format -style=file -i {} \;

echo "All '.cpp' and '.h' files have been formatted!"
