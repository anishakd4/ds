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

// so there is a way functions can share their local variables if they pass it as reference variables
void increment(int &n)
{
    n++;
}

// bad practice
// reference to stack memory associated with local variable 'a' returned
// a has scope bound to this function. After the function invocation system can reclaim this memory for something else. So
// this is dangerous. If we are doing this then should be aware what are we doing here.
int &f(int n)
{
    int a = n;
    return a;
}

// bad practice
// address of stack memory associated with local variable 'a' returned
// These will work but we might face issues
int *f2(int n)
{
    int a = n;
    return &a;
}

int main()
{
    int i = 10;
    int &j = i; // reference variable. We don't create new memory location for reference variable
    /*
    in symbol table i->400 and j->400

    __________________
    |       i=>400    |
    |       j=>400    |
    |_________________|
    */

    i++;
    cout << "j: " << j << endl;
    j++;
    cout << "i: " << i << endl;

    int k = 100;
    j = k;
    cout << "j: " << j << endl;
    cout << "i: " << i << endl;

    int a;
    a = 10; // this is fine it just means create a memory space for a and it has garbage value and then in next step we place 10 into it;
    // int &b; //error: declaration of reference variable 'b' requires an initializer. As this is a reference variable so we need it to
    // point to a existing location so we need to mention this at the very first step
    // b = a;

    increment(i);
    cout << "j: " << j << endl;
    cout << "i: " << i << endl;

    int &c = f(i);
    int *d = f2(i);

    return 0;
}