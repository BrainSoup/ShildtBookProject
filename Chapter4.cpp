//Chapter 4
#include <iostream>
#include <string>

using namespace std;

void Chapter4Func()
{
    cout << endl << "Chapter 4. Loops" << endl;

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
}