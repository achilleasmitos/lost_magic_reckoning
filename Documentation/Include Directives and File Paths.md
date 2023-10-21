# Include Directives and File Paths

## Absolute paths

It has been decided that the paths in our `#include` directives should be absolute paths, with the base path being that of the 'src' folder in the root of our project. This means that, in order to include a file that is in 'src/my_folder/my_included_file.h' anywhere in our project, one only needs to write `#include "my_folder/my_included_file.h"`.

In order to achieve that, we are making use of the `-I` build flag, specifying `${workspaceFolder}\\src` as the directory where the compiler should check for header files. Note that this directory must follow the `-I` flag directly, without space in-between them.
For more information on how this flag behaves, and the search paths of the compiler in general, plase read [this documentation page](https://gcc.gnu.org/onlinedocs/cpp/Search-Path.html) as well as [this StackOverflow answer](https://stackoverflow.com/questions/29000144/where-is-the-i-captial-i-path-relative-to-in-g) on the matter.

## Syntax

As stated above, one should refrain from using relative paths in `#include` directives. This rule can be overriden when the included file shares the same initial path with the includer. An example would be that of a 'name_helpers.h' file that resides inside the 'name_helpers' folder, that folder is adjacent to 'main_character.cpp' file and the first file is included in the latter. In that case, the include directive may simply be `#include "name_helpers/name_helpers.h"`.

Notice that even in the case of relative paths, we skip the `./` at the beginning of the path.

Last but not least, the order of the include directives is as follows:
1. the header file of the current source file (if applicable)
2. the 'utils' header file (if necessary)
3. any other files that we have created for our project in alphabetical order
4. an empty line
5. all other system includes (like `<iostream>`, `<string>` etc) in alphabetical order
