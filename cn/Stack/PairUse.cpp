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

#include "Pair.cpp"
int main()
{
    Pair<int, double> p;
    p.setX(34);
    p.setY(23423.4);
    cout << p.getX() << " " << p.getY() << endl;

    cout << "----------------------------------------------------------------" << endl;
    Pair<Pair<int, int>, int> p1;
    p1.setY(123456);
    Pair<int, int> p2;
    p2.setX(6789);
    p2.setY(24556);
    p1.setX(p2);
    cout << p1.getY() << " " << p1.getX().getX() << endl;

    return 0;
}