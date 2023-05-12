#include "handle_text_cmd.h"
#include "../print/print.h"

void utils::HandleTextCmd(std::ifstream& source_file,
	std::string& text,
	std::function<bool()> cmd_begins_ends)
{
	while (std::getline(source_file, text) && !cmd_begins_ends())
	{
		utils::Print({text});
	}
}
