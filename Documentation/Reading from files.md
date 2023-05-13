Situated in the 'utils' folder is a function called 'ReadFromFile'. This function is responsible to read from a supplied file path and handle the commands encountered.

Each text file that is meant to be part of the story has to follow a certain syntax in order for the above function to work properly. They consist of command blocks, each of which has the form:
`Command start`
`Parameters`
`Text`
`Command end`
At the end of this file you can find a list with all the available commands, what they do and examples on how to use them. You will also find common problems and troubleshooting advice when the game does not display what you intended.

## Common rules for commands
* All commands start on a new line with "@@@" followed by the command name and nothing else on the same line
* All commands end with "@@@" on its own new line
* All commands are written in the form of CAPITAL_LETTERS_SEPARATED_BY_UNDERSCORES
* Commands that require some arguments (like SLEEP_FOR) have the arguments immediately after their declarations, with any left-over text following their parameters (like CUSTOM_SPEED_TEXT)

## List of commands:

| Command           | Description   |
| :---              | :----         |
| TEXT              | Starts a block of text that will be rendered on the console with default text speed|
| CUSTOM_SPEED_TEXT | Starts a block of text that will be rendered on the console with the text speed (non-negative integer) defined on the second line of the block|
| SLEEP_FOR         | Contains one line (with a non-negative integer) that instructs the program to sleep for a certain amount of milliseconds|

## Examples
#### Printing a block of text on the console:
```
@@@TEXT
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Maecenas malesuada rutrum diam,
id tincidunt leo cursus at. Cras pretium, ex eget volutpat volutpat,
enim mi accumsan erat, sed faucibus massa nunc quis dolor. Sed vel pretium neque,
ut pretium nisi. Nam cursus purus nisi, et ultrices odio vulputate ac.

Morbi tellus eros, ornare sed luctus quis, imperdiet ac lorem.
Sed blandit risus sed massa imperdiet dictum. Quisque eu nisi pulvinar, commodo purus id,
vestibulum neque. In iaculis velit velit, pellentesque varius quam tempus id.
Nam id tortor sem. Sed lacinia dignissim nisl, non malesuada purus congue in.
@@@
```
##### Tips:
* Each line of text should not be longer than 80 characters, as it might not look good on the console. In the future, there might possibly even be a hard-coded upper limit in how long each line can be (for memory usage reasons).
* Do not write super long chunks of text. Divide your text into smaller, digestible paragraphs, and separate them by empty lines for more readability.
* Pay attention to where you might need a longer pause for dramatic effect. Or simply for the player to catch up to the text.

#### Text with different speed:
```
@@@CUSTOM_SPEED_TEXT
20
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Maecenas malesuada rutrum diam,
id tincidunt leo cursus at. Cras pretium, ex eget volutpat volutpat,
enim mi accumsan erat, sed faucibus massa nunc quis dolor. Sed vel pretium neque,
ut pretium nisi. Nam cursus purus nisi, et ultrices odio vulputate ac.

Morbi tellus eros, ornare sed luctus quis, imperdiet ac lorem.
Sed blandit risus sed massa imperdiet dictum. Quisque eu nisi pulvinar, commodo purus id,
vestibulum neque. In iaculis velit velit, pellentesque varius quam tempus id.
Nam id tortor sem. Sed lacinia dignissim nisl, non malesuada purus congue in.
@@@
```

##### Tips:
* Follow the tips from the TEXT example.
* The second line should only be a non-negative integer number, that indicates the milliseconds the program should sleep for in-between character renders. A comfortable number for this is 40.
* Do not overuse this command (there is a reason why a player can set their own preferred text speed!).

#### Pause the execution of the program:
```
@@@SLEEP_FOR
1500
@@@
```

##### Tips:
* The second line should only be a non-negative integer number, that indicates the milliseconds the program should sleep for.
* Use for dramatic effects, or as a means for the user to catch up to a large paragraph that has just been displayed.

## Troubleshooting:
If the program does not display the desired behavior, it is good to read the output as it often contains explanations pertaining to what went wrong.

A common problem is the mis-spelling of a command, resulting in the below print:
```
I do not know this comand yet...
The command you tried to use is: {command_name}
```
followed by the command you tried to use.

If nothing shows up in the command name, this signals to you that you have used an extra command end ("@@@") somewhere. Check that commands always have a single start and single end, as described above.

Another common mis-use is the attempt to nest different commands within each other (for example, having a SLEEP_FOR command inside a TEXT command). This is not (yet) possible! Commands should always be separate.

Also, remember that commands start and end on their own lines. You do not start/end a command in the middle of a line!
