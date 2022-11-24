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
    Student s1; // this will create a memory block.
    // As class has 2 ints and 1 char pointer it will create a memory block of almost 16 bytes,
    // but not exactly 16 bytes as there are much more deeper details to this which is not required at this point of time.

    cout << Student::totalStudents << endl;
    cout << s1.rollNumber << " == " << s1.age << endl;
    cout << "s1.totalStudents: " << s1.totalStudents << endl; // this is allowed but logically incorrect

    s1.totalStudents = 5;
    Student s2;
    cout << s2.totalStudents << endl;
    cout << s1.totalStudents << endl;
    cout << "Student::totalStudents: " << Student::totalStudents << endl;

    Student s3;
    Student s4;
    Student s5, s6, s7;
    cout << Student::totalStudents << endl;

    cout << "Student::getTotalStudents(): " << Student::getTotalStudents() << endl;

    // copy constructor
    char name[] = "abcd";
    Student s8(20, name);
    cout << "s8: " << endl;
    s8.display();

    name[3] = 'e';
    Student s9(24, name);
    cout << "s9: " << endl;
    s9.display();
    cout << "s8: " << endl;
    s8.display();

    Student s21(s8);
    cout << "s21: " << endl;
    s21.display();
    s8.name[2] = 'm';
    cout << "s21: " << endl;
    s21.display();
    // copy constructor

    Student *s10 = new Student();
    (*s10).age = 54;
    (*s10).rollNumber = 154;
    cout << "s10->age:" << s10->age << endl;
    s10->age = 24;
    s10->rollNumber = 154;
    cout << "s10->age:" << s10->age << endl;

    Student s11(10, 1001);
    cout << "s11: ";
    s11.display2();
    s11.name = name;

    Student s12(s11);
    cout << "s12: ";
    s11.display2();

    Student *s13 = new Student(20, 2001);
    cout << "s13: ";
    s13->display2();
    s13->name = name;

    Student s14(*s13);
    cout << "s14: ";
    s14.display2();

    Student *s15 = new Student(*s13);
    cout << "s15: ";
    s15->display2();

    Student *s16 = new Student(s11);
    cout << "s16: ";
    s16->display2();

    Student s18(20, 2001);
    Student s19(10, 1001);
    Student *s20 = new Student(30, 001);
    s19 = s18;
    cout << "s19: ";
    s19.display2();
    *s20 = s18;
    cout << "s20: ";
    s20->display2();
    s20->age = 67;
    s20->rollNumber = 890;
    s19 = *s20;
    cout << "s19: ";
    s19.display2();
}

// We can declare data members and functions as static members
// static means values of these properties should remain same for all objects, it should not depend on objects