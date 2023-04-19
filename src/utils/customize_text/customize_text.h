#pragma once

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

extern int g_text_size;
extern FontWeightValues g_text_weight;

/**
 * @brief A function that changes the basic aesthetics of the text. This is only in a real cmd,
 * and should probably be changed when an (inevitable) switch to virtual terminal happens.
 * For now, it works as a proof of concept, and a starting point for further development.
 * Read more: https://learn.microsoft.com/en-us/windows/console/console-font-infoex?redirectedfrom=MSDN
 *
 * @param font_size An integer indicating how large the font will be.
 * @param font_weight The weight of the font, one of: Light, SemiLight, Normal, SemiBold, Bold.
 * @param face_name A wchar_t string for the font typeface used.
 */
void CustomizeText(int font_size = g_text_size,
	FontWeightValues font_weight = g_text_weight,
	const wchar_t* face_name = L"Courier");
} // namespace utils
