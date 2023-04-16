# Code Format

## .clang-format

Checked-in into this repository, at the root folder where it _has_ to reside in order for it to take effect, is the .clang-format file that defines our desired code style. In order to use it in VSCode, all you have to do is open the root folder in the editor and install the C/C++ extension from the marketplace.

## .vscode/settings.json

In settings.json we have enforced the auto-format-on-save setting to be true, so that it saves us from the headache of whether a particular file is formatted or not. It is highly encouraged to leave it like so during your development, as it was decided not to have any automatic format-checker during pushes / pull-requests at the moment. If, for any reason, you have to disable it during development, you should run the following command before you push any changes to the repo to format all your C++ files:
```
    find . -regex '.*\.\(cpp\|h\)' -exec clang-format -style=file -i {} \;
```
The above should be run in your git-bash at the root folder of the repo, after you have installed clang-format via the command `npm install -g clang-format` (assuming you have already installed [Node.js](https://nodejs.org/en)).
