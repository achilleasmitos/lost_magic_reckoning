#include "handle_text_cmd.h"
#include "utils/utils.h"

void HandleTextCmd(std::ifstream& source_file,
	std::string& text,
	const std::function<bool()>& cmd_begins_ends)
{
	while (std::getline(source_file, text) && !cmd_begins_ends())
	{
		utils::Print({text});
	}
}
