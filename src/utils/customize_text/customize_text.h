#pragma once

#include <string>
#include <vector>

namespace utils
{
enum FontWeightValues
{
	Light = 100,
	SemiLight = 200,
	Normal = 400,
	SemiBold = 600,
	Bold = 800
};

// An integer indicating how large the font will be.
extern int g_text_size;
// The weight of the font, one of: Light, SemiLight, Normal, SemiBold, Bold.
extern FontWeightValues g_text_weight;
// A string for the font typeface used.
extern std::string g_text_face_name;

std::vector<std::string> const AVAILABLE_TEXT_FACE_NAMES{"Consolas",
	"DejaVu Sans Mono",
	"Liberation Mono",
	"Lucida Console",
	"MS Gothic"};

/**
 * @brief A function that changes the basic aesthetics of the text.
 * It sets the values of the global text variables to the appropriate places
 * in the console font infoex.
 *
 * Call this function after any change to the global text variables occurs,
 * for it to take effect.
 */
void CustomizeText();
} // namespace utils
