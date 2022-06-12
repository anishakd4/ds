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
#include "DynamicArray.cpp"

int main()
{
    DynamicArray d1;
    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);

    d1.print();

    DynamicArray d2(d1); // copy constructor
    DynamicArray d3;     // copy assignment operator
    d3 = d1;

    cout << "Before d1 changes" << endl;
    d2.print();
    d3.print();
    d1.add(100, 0);
    cout << "After d1 changes" << endl;
    d1.print();
    d2.print();
    d3.print();
    cout << d1.data << endl;
    cout << d2.data << endl;
    cout << d3.data << endl;

    return 0;
}