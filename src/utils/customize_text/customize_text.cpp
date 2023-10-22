#include "customize_text.h"

#include <codecvt>
#include <cwchar>
#include <locale>
#include <windows.h>

int utils::g_text_size = 16;
utils::FontWeightValues utils::g_text_weight = utils::FontWeightValues::Normal;
std::string utils::g_text_face_name = "Consolas";

static std::wstring to_wstring(const std::string& stringToConvert)
{
	std::wstring const wideString =
		std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(stringToConvert);
	return wideString;
}

void utils::CustomizeText()
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0; // The index of the font in the system's console font table.
	cfi.dwFontSize.X = 0; // A COORD structure that contains the width and height of each character in the font.
	cfi.dwFontSize.Y = g_text_size; //   The X member contains the width, while the Y member contains the height.
	cfi.FontFamily = FF_DONTCARE; // The font pitch and family. See also TEXTMETRICA.
	cfi.FontWeight = g_text_weight; // The font weight. The weight can range from 100 to 1000, in multiples of 100.
	std::wcscpy(cfi.FaceName, to_wstring(g_text_face_name).c_str()); // Copies the desired typeface over to FaceName.
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}
