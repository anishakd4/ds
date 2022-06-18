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
int main()
{
    vector<int> *vp = new vector<int>(); // dynamic allocation
    vector<int> v;                       // static allocation

    for (int i = 0; i < 100; i++)
    {
        cout << v.capacity() << " : " << v.size() << endl; // initially capacity will come as 0. Actually
        // underlying array is null at the beginning
        v.push_back(i + 1);
    }

    v.push_back(10);
    v.push_back(20);
    v.push_back(30); // in push current capacity will be seen whether we need to increase capacity or not.
    // All these things will be thought about

    v[1] = 100;

    v[3] = 10002;
    v[4] = 500; // we do directly this then vector won't be thinking about space and wether capacity needs to
    // be increased or not
    // it might happen that we are not writing to the memory alloted to the array. The memory where we might
    // be writing might not belong to us also

    cout << v[0] << endl;
    cout << v[1] << endl;
    cout << v[2] << endl;
    cout << v[3] << endl;
    cout << v[4] << endl;

    v.push_back(40); // don't use [] for inserting elements. Use it for getting value or updating the value
    v.push_back(50); // these will overwrite above values as for push_back still last element is at 2nd position

    cout << "--------------------------------" << endl;
    cout << v[0] << endl;
    cout << v[1] << endl;
    cout << v[2] << endl;
    cout << v[3] << endl;
    cout << v[4] << endl; // this won't throw error even if the position has garbage value

    cout << "Vector size:" << v.size() << endl;

    cout << v.at(2) << endl;
    cout << v.at(6) << endl; // this will throw error out of range

    return 0;
}