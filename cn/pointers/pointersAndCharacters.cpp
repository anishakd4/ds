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
    int arr[] = {1, 2, 3};
    char ch[] = "abc";
    cout << "arr: " << arr << endl;
    cout << "ch: " << ch << endl;
    //it will to the location and will start printing characters till it visits '\0' null character
    //reason being cout is implemented differently for characters and character pointers
    cout << "&ch: " << &ch << endl;

    char *c = &ch[0];
    cout << "c: " << c << endl;

    char c1 = 'a';
    char *pc = &c1;

    cout << "c1: " << c1 << endl;
    cout << "pc: " << pc << endl;

    char str[] = "abcde";
    //String literal
    //here first temp memory is created to store abcde. then array is allocated fresh storage and data is copied into it.
    char *pstr = "abcde";
    //here pointer is pointing to read-only temp memory. It can be crash if try to change it or it may not be crash.
    //So We should not use this approach.
    /*
    temp memory location 700:

                            _____________________________
                            | a b c d e \0               |
                            |____________________________|

    str memory location: 800:
                            _____________________________
                            | a b c d e \0               |
                            |____________________________|

    pstr = 

                            _____________________
                            | 700               |
                            |___________________|
    */
    return 0;
}