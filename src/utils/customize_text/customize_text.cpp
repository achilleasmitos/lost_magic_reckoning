#include "customize_text.h"
#include <cwchar>
#include <windows.h>

int utils::g_text_size = 16;
utils::FontWeightValues utils::g_text_weight = utils::FontWeightValues::Normal;

void utils::CustomizeText(int font_size, utils::FontWeightValues font_weight, const wchar_t* face_name)
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0; // The index of the font in the system's console font table.
	cfi.dwFontSize.X = 0; // A COORD structure that contains the width and height of each character in the font.
	cfi.dwFontSize.Y = font_size; //   The X member contains the width, while the Y member contains the height.
	cfi.FontFamily = FF_DONTCARE; // The font pitch and family. See also TEXTMETRICA.
	cfi.FontWeight = font_weight; // The font weight. The weight can range from 100 to 1000, in multiples of 100.
	std::wcscpy(cfi.FaceName, face_name); // Copies the desired typeface over to FaceName.
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}
