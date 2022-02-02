#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <climits>
#include <sys/time.h>
// climits for INT_MIN
#include <unordered_map>
using namespace std;

/*
Time complexity analysis: Idea is to figure out how good or bad this solution in terms of time & space required.
Below is experiment analysis of time.
cons of experiment analysis:
1. If we run our program again it will give different result
    Reason: when we run our program it is not the only program that runs. how much time processor will give to my program
    and other similar reasons will tell us how much time our program will take on the exact same input.
2. Test case generation.
    Reason:
        1 2 3 4 5
        Insertion sort: very fast
        Selection sort: slow
        Insertion sort and selection sort are almost sime time complexity algorithm but some test cases particular algorithms.
3. If a probelm comes and i figured out 10 solutions. How will I figure out which is better.I have to write code for
    each of them.
4. Time comsuming. Selection sort might take minutes and hours to sort 10 million intergers.

In general we try to find worst cases as we want to be sure our algorithm performs well in worst cases also.

BIG O notation
selection sort: 10n2 +5n + 8
insertion sort: 5n2 + 2n + 1000

for n-> pow(10, 5) 5n2 will dominate

can we actually say insertion sort to 5n2. as this is going to changed based on system. We can never actually say time.
We can just convey how many instructions it will take.

pow(10, 8) operations will remain same for all the systems, only thing will change is how much time its going to
take on different systems.

5n2 here n square will change, 5 is just a constant so we will ignore 5 also.

1. We will talk only about number of unit operations and not time
2. we will focus on higest power term.
3. don't care about the coefficient much

What is BIG O notation
algorithm A -> O(f(n))

Algorithm A is called Big O of f(n) if time taken by algorithm A for input n <= k*f(n)

For example :

Insertion sort f(n) = 5n2+10n+1000 <= 6n2
so time take by insertion sort is <= 6*n2
so insertion sort = O(n2)

For example:

Largest element in an array
_____________________________________
|   |   |   |   |   |   |   |   |   |
|___|___|___|___|___|___|___|___|___|

max=a[0]
if(max<a[0]){

}else{

}

Time taken = (k operations) n times
Time taken = (k+1)*n

For example:

Bubble sort:
each time we perform k steps for n-1 comparisions
then k steps for n-2 comparisions
then k steps for n-3 comparisions
bubble sort => (n-1)k + (n-2)k + (n-3)k + (n-4)k + (n-5)k + ...... + k
bubble sort => (k)*(n-1)*(n)/2 => k(pow(n,2)/2) - k(n/2) => (k/2)(pow(n,2)) => c*pow(n,2)
time taken bubble sort => c*pow(n,2)

so bubble sort is O(n2)

All these are called theorotical analysis.


Space complexity=space required as a f(n)
Here we are talking about auxiliary space means the extra space needed.
1. auxiliary space
2. Max space required at any point of time suring execution of program
3. recursion
_____________       _____________     ______________      _______________              _______________
|____________|  =>  |____________| => |_____________|  => |_____________| => ......... |______________|
fact(n)                 fact(n-1)           fact(n-2)           fact(n-3)               fact(0)
k space                 k space         k space             k space                     k space
space complexity = O(kn) = O(n)
In case of recursion we always have some space complexity it is never order of constant.

int factorial(int n){
    if(n==0){
        return 1;
    }
    return n*factorial(n-1);
}

Bubble sort
space complexity = O(i) constant space complexity
bubble sort(){
    int i,j, temp;
    12, 20 bytes max
}

Binary search(recursion):
n    =>    n/2     =>     n/4      =>     n/8    => ....... => 1
k           k               k               k
we have log(n) functions waiting in the call stack
so space complexity = klog(n) = O(log(n))

Merge sort:
n -> n/2 -> n/4 -> n/8 -> ...... -> 1
klog(n) + kn = O(n)

At any point of time max log(n) functions can be in the stack. any new function will be added only after removing some
function from the stack. So lets it takes k bytes for each function then total will be k*log(n)

when all the functions return at the top level func(n) will create a array of size n so,
klog(n) + kn = O(n)
*/
long timeInMicroseconds()
{
    struct timeval start;
    gettimeofday(&start, NULL);
    return (start.tv_sec * 1000000 + start.tv_usec);
}

void merge(int arr[], int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[start + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = start;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

int main()
{
    for (int n = 10; n <= 1000000; n *= 10)
    {
        int *arr = new int[n];
        long startTime, endTime;
        for (int i = 0; i < n; i++)
        {
            arr[i] = n - i;
        }
        startTime = timeInMicroseconds();
        mergeSort(arr, 0, n - 1);
        endTime = timeInMicroseconds();
        cout << "Merge sort for n = " << n << " size time= " << (endTime - startTime) << endl;
    }
    return 0;
}