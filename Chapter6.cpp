#include <iostream>
#include <string>
#include "ColorText.h"

using namespace std;

void OutputMass(int* mass, int lenth)
{
    for (; lenth > 0; lenth--)
        cout << *(mass++) << " ";
    cout << endl;
}

void Chapter6Func()
{
    PrintColorText("\nChapter 6. Pointers");

    //Pointer declaration
    int* i_ptr;

    int i = 10;
    //Pointer operators
    i_ptr = &i; // take address from variable i
    i = *i_ptr; // take value from pointer

    //Forbidden to address different types
    double d = 1;
    //i_ptr = &d; // cannot convert from 'double *' to 'int *', need explicit conversation
    //double* d_ptr = &i; //a value of type "int *" cannot be used to initialize an entity of type "double *"
    //But it's possible to make explicit conversation
    i_ptr = (int*)&d;

    //Assign value to pointer
    cout << "i = " << i << endl;
    *i_ptr = 11;
    cout << "(*i_ptr = 11); i = " << i << endl;
    (*i_ptr)++; //Round brackets required cause of operation priority
    cout << "(*i_ptr)++; i = " << i << endl;
    
    //Pointers and massives
    cout << "\nPointers and massives: " << endl;
    int massive[10] = {};
    int *m_ptr = massive;   //not indexed massive name generate const pointer to 0 element
    OutputMass(massive, 10);    //use massive as pointer parameter
    massive[4] = 4; 
    m_ptr[5] = 5;   //pointers can use indexers like massives
    *(m_ptr + 2) = 2;   //same instruction as above
    3[m_ptr] = 3;   //mechanics of indexers a[b] => *(a+b)
    3[&m_ptr[3]] = 6;
    OutputMass(m_ptr, 10);
    int* m[10]; //massive of int pointers
    //TODO add example (m_ptr = new int[];/m_ptr = int[];)

    //Possible pointer ariphmetic operations
    cout << "\nPointer ariphmetic operations: " << endl;
    i_ptr = &i;
    cout << "i_ptr = " << i_ptr << endl;
    i_ptr++;
    cout << "i_ptr++ : " << i_ptr << endl;
    i_ptr--;
    cout << "i_ptr-- :  " << i_ptr << endl;
    i_ptr+=5;
    cout << "i_ptr+=5 : " << i_ptr << endl;
    cout << "i_ptr-&i : " << i_ptr - &i << endl;
    //i_ptr + &i; //Error, pointer sum is prohibited
    cout << "&massive[6]-massive : " << &massive[6] - massive << endl;
    cout << "(char*)&massive[6] - (char*)massive : " << (char*)&massive[6] - (char*)massive << endl;

    //level of pointers
    int x, * p, ** q; //int, int *, int **
    x = 10;
    p = &x;
    q = &p;

    //Common case
    //WRONG
    int val = 0;
    /*
    int* p_val;
    *p_val = val;*/   //Assigning value to not initialised pointer may cause errors
    //CORRECT
    int* p_val1 = NULL; // or zero
    if (p_val1)
        *p_val1 = val;
}