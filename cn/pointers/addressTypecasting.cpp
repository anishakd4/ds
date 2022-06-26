#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <climits>
// climits for INT_MIN
#include <unordered_map>
using namespace std;

/*
int * p;
pointer p;

Why do we need to mention `int *` for creating a pointer, why can't we simply write `pointer` as a data type like int or char.
Because `int` in `int *` will tell us how to read the 4 bytes available as float also requires 4 bytes and also how many byes
we need to read. Float and in will interpret the same 4 bytes very differently. Thats why even if all pointers store just addresses we still need to mention type.

*/
int main()
{
    int i = 65;
    char c = i; // implicit typecasting
    cout << "c: " << c << endl;

    int *p = &i;
    // char *pc = p; //error: cannot initialize a variable of type 'char *' with an value of type 'int *'
    char *pc = (char *)p; // explicit typecasting

    cout << "p: " << p << endl;
    cout << "pc: " << pc << endl;

    cout << "*p: " << *p << endl;
    cout << "*pc: " << *pc << endl;
    cout << "*(pc+1): " << *(pc + 1) << endl;
    cout << "*(pc+2): " << *(pc + 2) << endl;
    cout << "*(pc+3): " << *(pc + 3) << endl;

    /*

    we might be thinking 65 would be stored like this:

        ________________________________________________
        |    0      |      0    |    0      |   65      |
        |___________|___________|___________|___________|

        *pc         *pc+1       *pc+2       *pc+3

        but in realty it stored like this:

        ________________________________________________
        |    65     |      0    |    0      |   0       |
        |___________|___________|___________|___________|


        Little endian(little end first, means last byte is stored at first place)
        Big endian

        most of the sytems are little endian
    */

    return 0;
}