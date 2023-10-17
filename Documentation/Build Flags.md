### Build Flags

In our project, we are using certain build flags that may seem strict (and rightly so) to someone who is not used to them. Below, we explain in brief some of them, so that one knows what these flags do, and most importantly what to look out for when developing C++ code. More detailed explanations of each of these flags can be found in the [official docs](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html).

**-Wall**: this flag is actually a shortcut that flips on many different build flags that closely check our code for not-so-standard syntax and even perhaps minor inconsistencies that may lead to bugs. It is the most common cause for compiler errors, and each error should be analyzed on its own to be taken down.

**-Wextra**: this turns on flags that even '-Wall' leaves off, and makes our codebase even more standard compliant.

**-Wpedantic** and **-pedantic-errors**: issue all warnings (and turn them into errors) demanded by strict ISO C and ISO C++.

**-Werror**: turn all warnings into errors. We do not want even one warning in our code!

**-Wmissing-declarations**: all functions should have a header file declaration. If a function is local to just one source file (such as helper functions already used in our project), then they should be marked as `strict` in the very front of their definition.

**-std=c++20**: defines the C++ ISO standard we use.
