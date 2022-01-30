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
    string *sp = new string; // dynamic allocation of string
    *sp = "anish";
    cout << *sp << endl;
    cout << sp << endl;

    string s = "abc"; // static allocation of string
    // cin >> s; //anish kumar will fail here as space is there. cin breaks around space
    getline(cin, s);
    cout << s << endl;

    s = "manish kumar";
    cout << s << endl;
    s[0] = 'r'; // strings can be treated as array. we can replace its char by char
    cout << s << endl;

    string s1 = "abc";
    cout << s1 << endl;

    string s2 = s + s1; // we can concat string
    cout << s2 << endl;

    cout << s2.size() << endl;
    cout << s2.length() << endl;

    cout << s2.substr(10) << endl;    // gets everything after 10
    cout << s2.substr(10, 3) << endl; // gets everything after 10 but only length 3

    cout << s2.find("an") << endl; // returns position for the first occurrence of an in the string s2

    return 0;
}