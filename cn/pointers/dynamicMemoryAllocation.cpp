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

/*
int arr[20];

int n;
cin>>n;
int arr[n]
This works on most of the compilers but we should do this. C++ doesn't guarantee that this will work on systems or compilers.
we should not create a variable size array. At compile time it should be clear what is the size of the array.

Whenever we allocate memories there are two types of memories stack and heap. Heap is bigger than stack.
Whenever program starts it start with a stack memory.

            Stack                       Heap
            _________________           _________________
            |               |           |               |
            |               |           |               |
            |               |           |               |
            |               |           |               |
            |               |           |               |
            |_______________|           |               |
                                        |               |
                                        |_______________|

            int i = 10;
            int a[20];
            these are pretty small and can we easily handled in stack

            int a[20000];
            this is huge but as this is known at compile time so system makes the stack that big so that program
            can accomodate this bug data in stack.

    Problem comes when we do like this
    int n;
    cin>>n;
    int arr[n]

    system is not aware how bug stack it needs to start with and it can increase stack after starting the program.
    if n is way to big and stack might not be able to accomodate arr[n]

    for stack we decide at compile time. We say this static allocation as its already decided.
    for heap we decide at run time. We say this dynamic memory allocation.

*/
using namespace std;
int main()
{
    int i = 10;       // in stack
    int *p = new int; // in heap
    delete p;         // after usage is complete call delete p then heap memory will be released.
    // pointer 8 bytes we don't need to worry as it will cleared after scope
    // after delete don't use the memory as its not ours now.
    // single element deletion

    // if we want we can do this:
    p = new int; // as p was not deleted but the memory pointed by p was deleted;
    delete p;
    p = new int[8];
    delete[] p; // array deletion
    /*
                Stack                       Heap
            _________________           _________________
            |               |           |               |
            |        p      |           |   new int     |
            |    8 bytes    |           |    4 bytes    |
            |               |           |               |
            |               |           |               |
            |_______________|           |               |
                                        |               |
                                        |_______________|

    new in; alone is useless as it is returning address to make it useful we need to store
    *p = new int;
    */
    *p = 10;
    cout << (*p) << endl;

    double *pd = new double;
    char *c = new char;

    int *pa = new int[50]; // in heap. 8 bytes in the stack and 200 bytes in the heap.
    int n;
    cin >> n;
    int *pa2 = new int[n]; // we can use this exactly as array
                           // this is fine now  and in heap. So now we don't need to be aware whats the size of the array we need, we can ask at run time

    /*
    main{
        if(){
            int i=10; //this will be auto cleared after this if block
        }
    }
    */

    // while (true)
    // {
    //     // int k = 10;// each time 4 bytes is cleared and new 4 bytes are allocated
    //     int *p = new int;
    //     // 12 bytes. pointer 8 bytes will be cleared with each call but 4 bytes of int will remain. Its waiting you might use
    // }

    /*
    Static                          |               Dynamic
                                    |
    Memory will be  auto released   |  Manual release is required
    on basis of scope               |
                                    |
    */

    return 0;
}