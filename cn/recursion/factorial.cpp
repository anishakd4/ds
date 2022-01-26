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
causes of segmentation fault
1. array size is 10 and we are calling 25th or 24th element
2. you asked for memory and it doesn't have that memory
*/

int factorial(int n)
{
    cout << "n: " << n << endl;
    if (n == 0)
    {
        return 1;
    }
    int smallOutput = factorial(n - 1);
    return n * smallOutput;
}

int main()
{
    int n;
    cin >> n;
    int output = factorial(n);
    cout << output << endl;
    /*

        this is called call stack
        ________________
        |               |
        |   fact(0)     |
        |   fact(1)     |
        |   fact(2)     |
        |   fact(3)     |
        |   fact(4)     |
        |   main        |
        |_______________|


        main    =>  fact(4)     =>  fact(3)     =>      fact(2)     =>      fact(1)     =>      fact(0)
        line 35     line 27         line 27             line 27             line 27             return 1

    */
    return 0;
}