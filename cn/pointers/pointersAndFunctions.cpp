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

void print(int *p)
{
    cout << *p << endl;
}

void incrementPointer(int *p)
{
    p++;
}

void increment(int *p)
{
    (*p)++;
}

// arr is passed as pointer actually
int sum(int arr[], int size)
{
    cout << "sizeof(arr): " << sizeof(arr) << endl;
    return 0;
}

// if arr is passed as pointer actually then lets try pointer
// even if arr is pointer we can write arr[i] as this will be treated as *(arr+i)
int sum1(int *arr, int size)
{
    cout << "sizeof(arr): " << sizeof(arr) << endl;
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans = ans + arr[i];
    }
    return ans;
}

int main()
{
    int i = 10;
    int *p = &i;
    print(p);

    cout << "p: " << p << endl;
    incrementPointer(p);
    cout << "p: " << p << endl;

    /*
                    MAIN        |   incrementPointer
                                |
                    ________    |       ____________
            p       | 790   |   |  p    |  790      |
                    |_______|   |       |___________|
                                |
                                |  p = p+1
    memory location of i = 790  |       ____________
                                |       |  794      |
                                |       |___________|
                                |
    */

    cout << "*p: " << (*p) << endl;
    increment(p);
    cout << "*p: " << (*p) << endl;

    int arr[10];
    cout << "sizeof(arr): " << sizeof(arr) << endl;
    sum(arr, 10);

    cout << "sum: " << sum(arr, 10) << endl;
    cout << "sum1: " << sum1(arr + 3, 7) << endl;
    // here we passing part of the array

    return 0;
}