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

int max(int a, int b)
{
    return a > b ? a : b;
}

inline int max2(int a, int b)
{
    return a > b ? a : b;
}

// default value given to si. All default variables should be at the right most places in the function call.
// function(normal, default, normal, default) this is wrong
// function(normal, normal, default, default) this is correct
int sum(int arr[], int size, int si = 0)
{
    int ans = 0;
    for (int i = si; i < size; i++)
    {
        ans = ans + arr[i];
    }
    return ans;
}
int main()
{
    int a, b;
    cin >> a >> b;

    int c = (a > b) ? a : b;
    c = max(a, b); // each time it will go to the function and return the value and then value is pushed to c. So a performance lag
    c = max2(a, b);
    // for inline function compiler will copy the function body at the place where its getting called. So we made
    // our code readable plus there is no performance lag

    int x, y;
    cin >> x >> y;

    int z = (x > y) ? x : y;
    x = max(x, y);
    x = max2(x, y);

    /*
    so if we try to make all functions (big functions) inline then:
    1. a.out file will be bulkier
    2. when we write inline then we hint the compiler to please do it but its compiler's decision to do it or not
    3. if single line function compiler will do it, if 2-3 lines it might do it might not, more than these number of lines it won't do
    */

    int arr[20];
    cout << sum(arr, 20, 0) << endl;
    cout << sum(arr, 20) << endl; // we can skip default values
    cout << sum(arr, 20, 5) << endl;

    return 0;
}