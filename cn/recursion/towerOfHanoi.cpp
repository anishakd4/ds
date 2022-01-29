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
void towerOfHanoi(int n, char from_rod, char aux_rod, char to_rod)
{
    if (n == 0)
    {
        return;
    }
    if (n == 1)
    {
        cout << from_rod << " " << to_rod << endl;
        return;
    }
    towerOfHanoi(n - 1, from_rod, to_rod, aux_rod);
    cout << from_rod << " " << to_rod << endl;
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
}

int main()
{
    int n;
    cin >> n;
    towerOfHanoi(n, 'a', 'b', 'c');
    return 0;
}