#include "clear_screen.h"
#include "print.h"

#include <iostream>

void utils::ClearScreen()
{
	utils::Print({"The screen will now be cleared."});
	system("pause");
	system("CLS");
}
