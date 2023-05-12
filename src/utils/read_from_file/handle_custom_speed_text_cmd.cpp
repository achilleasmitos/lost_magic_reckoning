#include "handle_custom_speed_text_cmd.h"
#include "../print/print.h"

void utils::HandleCustomSpeedTextCmd(std::ifstream& source_file,
	std::string& text,
	std::function<bool()> cmd_begins_ends)
{
	std::getline(source_file, text);
	int sleep_for_ms = std::stoi(text);

	while (std::getline(source_file, text) && !cmd_begins_ends())
	{
		utils::Print({text}, sleep_for_ms);
	}
}
