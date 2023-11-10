# Code Format

## .clang-format

Checked-in into this repository, at the root folder where it _has_ to reside in order for it to take effect, is the .clang-format file that defines our desired code style. In order to use it in VSCode, all you have to do is open the root folder in the editor and install the C/C++ extension from the marketplace.
_Note:_ We are currently using clang-format version 17, so make sure you have that version installed on your local machine. Follow the instructions from [here](https://www.msys2.org/docs/updating/) in order to update your local packages.

## .vscode/settings.json

In settings.json we have enforced the auto-format-on-save setting to be true, so that it saves us from the headache of whether a particular file is formatted or not. It is highly encouraged to leave it like so during your development, as it was decided not to have any automatic format-checker during pushes / pull-requests at the moment. If, for any reason, you have to disable it during development, you should run the following command before you push any changes to the repo to format all your C++ files:
```
    find . -regex '.*\.\(cpp\|h\)' -exec clang-format -style=file -i {} \;
```
The above should be run in your git-bash at the root folder of the repo, after you have installed clang-format via the MSYS2 UCRT64 terminal. A `runFormatter.sh` script has been created in the root folder of our repo in order to make it even easier to format the whole repository.

## Troubleshooting:
If clang-format does not get applied automatically when you hit save (or _some_ format gets applied, but not the one we have specified in '.clang-format'), then simlpy select a block of code inside a .cpp file, right-click it, choose 'Format Selection With...' and when prompted select 'Configure Default Formatter'; set that to Clang-Format.
