#include "customize_text.h"

#include <iostream>
#include <unordered_map>
#include <windows.h>

int utils::g_text_size = 16;
utils::FontWeightValues utils::g_text_weight = utils::FontWeightValues::Normal;
std::string utils::g_text_face_name = utils::AVAILABLE_TEXT_FACE_NAMES[0];

std::unordered_map<std::string, std::wstring> const string_to_wstring_face_name_map{
	{utils::AVAILABLE_TEXT_FACE_NAMES[0], L"Consolas"},
	{utils::AVAILABLE_TEXT_FACE_NAMES[1], L"DejaVu Sans Mono"},
	{utils::AVAILABLE_TEXT_FACE_NAMES[2], L"Liberation Mono"},
	{utils::AVAILABLE_TEXT_FACE_NAMES[3], L"Lucida Console"},
	{utils::AVAILABLE_TEXT_FACE_NAMES[4], L"MS Gothic"}};

static std::wstring to_wstring(const std::string& textFaceNameToConvert)
{
	const auto it = string_to_wstring_face_name_map.find(textFaceNameToConvert);
	if (it != string_to_wstring_face_name_map.end())
	{
		return it->second;
	}

	std::cerr << "The font face " << it->first
			  << " could not be converted to a known wide-string font face.\n";
	return L"Consolas";
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
