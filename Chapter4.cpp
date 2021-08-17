//Chapter 4
#include <iostream>
#include <string>
#include "ColorText.h"

using namespace std;

void Chapter4Func()
{
    PrintColorText("\nChapter 4. Loops");

    //If
    if (1)
    {
        //break;    //Error, break can be used only in switch and loop statements
        //continue;   //Error, only in loop statements
    }

    //Loops
    cout << "for(int i=0; i<3; i++)" << endl;
    for (int i = 0; i < 3; i++)
        cout << i << " ";
    cout << endl;

    cout << "for(int i=0; i<3; ++i)" << endl;
    for (int i = 0; i < 3; ++i)
        cout << i << " ";
    
    cout << endl;
    cout << "for (int i = 0, j = 0; i < 3; i++, ++j)" << endl;
    for (int i = 0, j = 0; i < 3; i++, ++j)
        cout << "i=" << i << " j=" << j << endl;
    
    //Also there is while() and do{}while()
    
    //Switch
    int n = 1, skip = 1;
    cout << "Switch(n): n=" << n << endl;
    switch (n) {
        case 0: cout << 1;
            break;  //stops execution of switch
        case 1: cout << 1;
            if (!skip)  //skips "cout << 2;" cause "case 2:" is not instruction, it's just label
        case 2: 
            cout << 2;
            if (!skip)
                break;  //Whithout "break;" instruction switch continue execution of next inctructions
        //case 1: break;    //Compile error, 2 similar cases is prohibited
        case -1:
        case 3:
            cout << 3;

        default: cout << 4;
    }
    cout << endl;
}