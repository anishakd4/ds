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
    int *p;
    char *q;
    double *r;
    float *s;
    cout << sizeof(p) << endl
         << sizeof(q) << endl
         << sizeof(r) << endl
         << sizeof(s) << endl;
    //generally these all will come same but it depends on compiler these value might come different.
    //But all these variables just need to store addresses so these should generally come same.

    int i = 10;
    int *a = &i;
    cout << "a: " << a << endl;
    a = a + 1;
    //This doesn't adds 1 to the address, but this means we want to move to the next integer.
    //As sizeof(int) is 4 so a+1 will add 4 to the address stored at a.
    cout << "a: " << a << endl;
    a++;       //move to the next integer
    a--;       //move to the pervious integer
    a = a + 2; //move to 2 integers ahead

    /*
    Pointer arithemetic makes sense only in the case of arrays

    _______________________________________________________
    |_______|_______|_________|________|__________|________|
        p+0     p+1      p+2     p+3        p+4        p+5
        a[0]    a[1]    a[2]    a[3]        a[4]       a[5]
    */

    double d = 12.2;
    double *dp = &d;
    cout << "dp: " << dp << endl;
    dp++; //This means move to the next double so it will add 8 to the address stored at dp as sizeof(double) is 8
    cout << "dp: " << dp << endl;

    return 0;
}