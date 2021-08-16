#include <iostream>
#include "Chapter3.h"
#include "Chapter4.h"
#include "Chapter5.h"
#include "Chapter6.h"
#include "Chapter8.h"
#include "Chapter9.h"
#include "Chapter10.h"
#include "Chapter11.h"

int global_var = 0;

int main()
{
    Chapter3Func();
    std::cout << std::endl;
    Chapter4Func();
    Chapter5Func();
    Chapter6Func();
    Chapter8Func();
    Chapter9Func();
    Chapter10Func();
    Chapter11Func();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
