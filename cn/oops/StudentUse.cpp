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

#include "Student.cpp"
int main()
{
    Student s1;

    cout << Student::totalStudents << endl;
    cout << s1.rollNumber << " == " << s1.age << endl;
    cout << s1.totalStudents << endl; // this is allowed but logically incorrect

    s1.totalStudents = 5;
    Student s2;
    cout << s2.totalStudents << endl;
    cout << s1.totalStudents << endl;
    cout << Student::totalStudents << endl;

    Student s3;
    Student s4;
    Student s5, s6, s7;
    cout << Student::totalStudents << endl;

    return 0;
}

// We can declare data members and functions as static members
// static means values of these properties should remain same for all objects, it should not depend on objects