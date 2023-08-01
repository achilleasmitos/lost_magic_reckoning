Situated inside the 'utils' folder are the functions called `SaveGame` and `LoadGame`. These functions are responsible for saving the current game state to a file called 'save_file.json' and reading from it to update the game state respectively. Both make use of the JSON interaction API (which can also be found inside the 'utils' folder) as well as the `std::unorder_map` structure to switch between file and game variables.

### Overview
The save function imports the main character object, then creates an unordered map with its values as well as the global values for the game settings. It then passes the populated map to `WriteToJSON` which is responsible to create the 'save_file.json'.
The load function imports the main character, then creates an unordered map from a call to `ReadFromJSON`. It finally updates the member variables of the main character as well as the global variables for the game settings with the values that the populated map has. The load function also has some error handling in place, in case something goes awry with the reading/assigning procedure.

### Keys
Since both save and load functions make use of map keys to write to / read from JSON, those keys have to stay up-to-date with each other. For example, if the save function creates a key called 'game_settings_text_weight' , then the load function also has to try and read from that same key for the value associated with it.

### The save file
The save file is, as stated, a JSON file, which is readable by both human and machine and easily importable into many programming languages. Moreover, it is a *simple* JSON, meaning that each of its values is a simple string (i.e. does not have objects, arrays and such as values). This is due to a constraint by the JSON API developed by us for this purpose. It is up to the save and load functions to transform these strings into the appropriate types for the game variables and vice-versa.

### Example of a save file:
```
{
	"game_settings_text_weight": "400",
	"game_settings_sleep_for_ms": "0",
	"game_settings_text_size": "24",
	"mc_name": "Achilleas",
	"mc_charisma": "14",
	"mc_class": "Wizard",
	"mc_strength": "9",
	"game_settings_sound_volume": "500",
	"mc_ac": "10",
	"mc_speed": "30",
	"mc_dexterity": "7",
	"mc_hp": "10",
	"mc_constitution": "11",
	"mc_race": "Human",
	"mc_intelligence": "15",
	"mc_wisdom": "15"
}
```
