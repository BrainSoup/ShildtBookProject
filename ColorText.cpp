#include <iostream>
#include <windows.h>
#include "ColorText.h"

using namespace std;

void PrintColorText(const char * text, TextColor tc)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, tc);
    cout << text << endl;
    SetConsoleTextAttribute(hConsole, TextColor::WhiteText);
}