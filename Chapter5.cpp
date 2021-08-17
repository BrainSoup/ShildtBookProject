#include <iostream>
#include <cstring>
#include "ColorText.h"

using namespace std;

void OutputMass(int mass[], int lenth)
{
    for (int i = 0; i < lenth; i++)
        cout << mass[i]<< ", ";
    cout << endl;
}

void TestFunc1(int mass[5]) {}
void TestFunc2(int (&mass)[5]) {} // (&mass)[5] Reference to massive

void Chapter5Func()
{
    PrintColorText("\nChapter 5. Massives");

    //Simple massive declaration
    int m_int[10];  //massive declared and memory allocated but not initialised
    char m_char[20];

    //massive initialization
    int m1_int[10] = { 0, 1, 2, 3 };
    //m_int = { 0, 1, 2, 3 };   //massive initialization can be done only in declaration statement
    cout << "int m_int[10]; Contains:";
    OutputMass(m_int, 10);  //contains trash

    //not initialized elements seted to zero during init statements
    cout << "int m1_int[10] = { 0, 1, 2, 3 }; Contains:" ;
    OutputMass(m1_int, 10);

    //Massives behaves like 'type * const' in terms of assignment
    //m_int = m1_int;   //Error can't modify massive
    //m_int++;  //Error can't modify massive

    //there is no compile or runtime check on massive borders
    cout << "In 'int m1_int[10]' m1_int[11] = " << m1_int[11] << endl;

    //Here compiler autodefine lenth of massive by initializator
    char m1_char[] = "Some string";
    int m2_int[] = {1, 2, 3, 4};

    //Simple string commands
    cout << "Lenth of 'char m1_char[] = \"Some string\";' is " << strlen(m1_char) << endl;
    strcpy_s(m1_char, "String");
    cout << "After 'strcpy(m1_char, \"String\");' Lenth is " << strlen(m1_char) << endl;

    //Two dimension massive and its init
    int m3_int[][2] = { {1,2}, {2,3}, {3,4} };
    int m4_int[3][2] = { 1, 2, 3, 4, 5, 6 };

    //Massive as func params
    TestFunc1(m_int);   //Ok
    //TestFunc2(m_int);   //int (&mass)[5] cannot be initialised with int mass[10]. There must be equal elements num
}