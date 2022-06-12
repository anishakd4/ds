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
#include "Fraction.cpp"
int main()
{
  Fraction f1(10, 2);
  Fraction f2(15, 4);

  Fraction f3 = f1.add(f2);
  Fraction f4 = f1 + f2;

  f1.print();
  f2.print();
  f3.print();
  f4.print();

  Fraction f5 = f1 * f2;
  f5.print();

  if (f1 == f2)
  {
    cout << "Equal" << endl;
  }
  else
  {
    cout << "NOT Equal" << endl;
  }

  f1.print();
  ++f1;
  f1.print();
  Fraction f6 = ++f2;
  f2.print();
  f6.print();

  Fraction f7(10, 2);
  Fraction f8 = (++(++f7));
  f8.print();

  cout << "POST INCREMENT" << endl;
  Fraction f9(10, 2);
  Fraction f10 = f9++;
  f9.print();
  f10.print();

  cout << "POST INCREMENT NESTED INCREMENT" << endl;
  Fraction f11(10, 2);
  Fraction f12 = ((f11++)++); // Nesting is not allowed on post increment even though this won't give any errors,
  // results might be unpredictable
  f11.print();
  f12.print();

  cout << "+= operator overloading" << endl;
  Fraction f13(10, 3);
  Fraction f14(5, 2);
  (f13 += f14) += f14;
  f13.print();
  f14.print();

  return 0;
}