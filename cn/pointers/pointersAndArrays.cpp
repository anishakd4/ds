#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <climits>
//climits for INT_MIN
#include <unordered_map>
using namespace std;
int main()
{
    int arr[10];
    /*
    This will create 40 bytes storage for array
    _________________________________________________________
    |________________________________________________________|

    a is basically name for this 40 bytes
    in symbol table there will be a entry of a = starting address of this 40 bytes which is same as address of arr[0] i.e. &arr[0]
    */

    cout << "arr: " << arr << endl;
    cout << "&arr[0]: " << &arr[0] << endl;
    //So arr can be treated almost exactly like pointer

    cout << "*arr: " << (*arr) << endl;
    arr[0] = 5;
    arr[1] = 10;
    cout << "*arr: " << (*arr) << endl;
    cout << "*(arr+1): " << (*(arr + 1)) << endl;
    /*
    arr[i] -> *(arr+i) 

    i[arr] -> *(i+arr) this will also work

    so arr[i] <-> *(arr+i) <-> i[arr]
    */
    cout << "1[arr]: " << 1 [arr] << endl;

    cout << "sizeof(arr): " << sizeof(arr) << endl;
    cout << "arr: " << arr << endl;
    cout << "&arr: " << &arr << endl;
    /*
    Although arr can be treated as pointer but there are couple of differences
    sizeof(arr) = 40 as in symbol table its mentioned that it is a array of size 10
    sizeof(pointer) = 8

    all these difference is because for pointers another 8 byte memory is created for it and save do to symbol table
    but for arrays not extra storage is created. In symbol arr = address of array is stored

    arr[10]
                    memorylocation = 780
                        _________________________________
                        |________________________________|

                    symbol table:
                        _____________
                        |arr=780    |
                        |           |
                        |           |
                        |           |
                        |           |
                        |___________|

    arr and &arr prints same but pointer and &pointers prints different.
    Reason: for storing pointers another storage is created but not arrays(arrays are just entered in the symbol table).
    */

    //arr = arr + 3; array can not be reassigned. Something entered in a symbol table cannot be changed.

    int *ptr = arr;
    cout << "ptr " << ptr << endl;

    //You can't do array = pointer but you can do pointer = array

    return 0;
}