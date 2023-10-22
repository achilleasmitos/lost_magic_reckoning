# Build Tasks

The '.vscode' folder contains the 'tasks.json' file that decribes the different tasks we have defined for our project. Currently, those are two build tasks, one for Debug builds, the other for Release builds.

### Debug build

This is the default task of VSCode (easily run by `Ctrl+Shift+B`). It turns on the `-g` flag of the compiler for debug symbols, and contains no optimizations beyond that. It is used for development purposes.

### Release build

This task can only be run by the 'Terminal > Run Task...' menu option of VSCode. It defines the preprocessor flag `-DRELEASE_BUILD` which changes certain variable values (mainly paths to resources) inside the code, as well as the `-Os` optimization flag (optimize like `-O2` but make the size as small as possible). This build is not meant to be run where it is first output, but rather be used by the 'installer/installer.sh' script which bundles it inside a Release folder alongside the resources. See the installer README and Instructions for more info, as well as guidelines on the release process.
