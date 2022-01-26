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

// This gives the contract the this function won't change the value at the storage
void g(const int &a)
{
    // a++;//error
}
// This gives the contract the this function won't change the value at the storage
void f(const int *p)
{
    //(*p)++; //error
}
int main()
{
    //***********int variable************//
    int i = 10;
    i = 12;

    //***********constant variable************//
    const int j = 10;
    int const y = 10; // we can write const int or int const
    // j = 12; //error.you can not change a const value

    // const int k; //error. If we don't initialize it here it will always have garbage value so C++ doesn't allow this.
    // So we need to initialize constant variable here itself
    //  k = 30;

    //***********constant reference variable************//
    int m = 10;
    const int &x = m; // constant reference from a non const integer
    /*
    symbol table:                       memory location: 800
        _____________                           ____________________
        |           |                           |        10         |
        |m->800     |                           |                   |
        |x->800     |                           |___________________|
        |           |
        |___________|

        m->800(can change the value at 800)
        x->800(path is constant we can't change value at the location its pointing to)

        storage is not constant its just the paths are constant.
        Here out of two paths x is constant but m is not , so we can change value at storage using m
    */
    // x++; // error
    cout << "x: " << x << endl;
    m++;
    cout << "x: " << x << endl;

    //**********const reference from const int***********//
    const int j2 = 10;
    const int &k2 = j2;
    // j2++; // error
    // k2++; // error

    //***************reference from const int**************//
    int const j3 = 123;
    // int &k3 = j3; //error
    // j3 only has Read access to its memory then how can k3 will ever get read and write access to the memory

    //***********Constant pointers***************//
    const int n = 10;
    // int *pn = &n; // error// you can't store address of a const integer into a normal pointer.
    // You only have read access to the storage so you can't facilitate a write allowed path to the storage
    const int *pn = &n; // constant pointer from a int. This is fine
    // This should be read like pn is a pointer to a constant int
    //(*pn)++; // error
    int q = 20;
    int const *pq = &q; // This should be fine
    cout << "*pq: " << (*pq) << endl;
    q++;
    cout << "*pq: " << (*pq) << endl;

    int e = 10;
    int d = 20;
    int const *pe = &e; // pe is a pointer to a constant int
    //(*pe)++;//error
    pe = &d;
    int *const pd = &d; // pd is a const pointer to a integer. pd is constant and where pd is pointing thats not constant.
    (*pd)++;
    cout << "d: " << d << endl;
    // pd = &e; //error
    int const *const p3 = &e; // p3 is a const pointer to a const integer
    //(*p3)++;
    // p3 = &d;
    return 0;
}