#include <iostream>
#include <windows.h>

using namespace std;

void PrintColorText(const char * text)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 2);
    cout << text << endl;
    SetConsoleTextAttribute(hConsole, 15);
}