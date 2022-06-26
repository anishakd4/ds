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
        int i = 20;
        /* Means I ask system I need a variable where please put 10.
        So system will create a 4 byte storage for me
        and will put 10 at that memory location.

        here "i" is the way through which we get know where it is stored.

            symbol table:
                    _____________
                    |i->700     |
                    |j->800     |
                    |k->900     |
                    |           |
                    |           |
                    |___________|
            This is called symbol table. This is made at compile time.
            At compile time itself it is stored where i or j
            or k will be stored.
            So if i need to get I then I will go to symbol table
            and get that its and 700 memory location and symbol
            table only will tell that we need to read a int variable so system will read it as a integer variable.

            For every variable that you are creating the system is storing where is the variable actually stored in memory and it also stores the type of the variable also.
            So, whenever we will talk about "i" variable we will know it is stored at memory location 700 and it is also a integer so i will go to the location 700
            and we will read 4 bytes as integer takes 4 bytes in memory
            */

        i = i + 5;
        cout << "i= " << i << endl;

        int j;
        cout << &j << endl; // addressof operator. This is print the address of j means where is j stored.
        // Even if i don't put any value in j still i memory location is given to j
        // This is in hexadecimal. hexadecimal means 16 base. so it will start from 0,1,.....,9a.....f where f means 15 e means 14 and so on
        //
        // 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
        // 0 1 2 3 4 5 6 7 8 9 a  b  c  d  e  f

        int *p;
        p = &j;
        // The way i am storing integer in int and character in char. The same way i want to store address in some type of variable.
        // So pointers are variables which can store address of other variables.
        // Now we have two ways to reach the same memory location
        // int * p(means p is a pointer(*) to a integer(int))

        // int               *      p
        // to a integer   pointer   p is a

        cout << p << endl;
        cout << &j << endl;
        // As you can see value of p and address of j are same

        float f = 10.2;
        float *pf = &f; // float pointer

        double d = 10.2;
        double *pd = &d; // double pointer

        cout << "*pf: " << *pf << endl; // dereference operator. This will get the value from the location whose address is stored in the pointer

        int k = 20;
        int *ptr = &k;
        /*
            memory location for k=700
            ____________________________
            |     20                    |
            |___________________________|

        k=20
        ptr=&k
            memory location for ptr=890
            ____________________________
            |         700               |
            |___________________________|

            symbol table
            _____________
            |k->700     |
            |ptr->890   |
            |           |
            |           |
            |           |
            |___________|

    */
        cout << "sizeof(k): " << sizeof(k) << endl;
        cout << "sizeof(ptr): " << sizeof(ptr) << endl;
        // it can be 4 or 8. Closely related to 32 or 64 bit but that also is not compulsary.

        k++;
        /*
    k=20;
    k++;
            memory location for k=700
            ____________________________
            |     21                    |
            |___________________________|

        k=20
        PTR=&K
            memory location for ptr=890
            ____________________________
            |         700               |
            |___________________________|

            symbol table
            _____________
            |k->700     |
            |ptr->890   |
            |k->900     |
            |           |
            |           |
            |___________|

    */
        cout << "k: " << k << endl;
        cout << "*ptr: " << *ptr << endl;

        int a = k; // we can also write *ptr. k or *ptr point to same 4 bytes
        a++;
        /*
    k=20;
    a=k;

    memory location for k=700
            ____________________________
            |     21                    |
            |___________________________|

    memory location for a=800
            ____________________________
            |     21                    |
            |___________________________|

    a++;

    memory location for k=700
            ____________________________
            |     21                    |
            |___________________________|

    memory location for a=800
            ____________________________
            |     22                    |
            |___________________________|

    */

        (*ptr)++; // we can treat *ptr exactly like integer here

        cout << "a: " << a << endl;
        cout << "k: " << k << endl;

        *ptr = 25;
        cout << "k: " << k << endl;
        cout << "*ptr: " << *ptr << endl;

        (*ptr)++;
        cout << "k: " << k << endl;
        cout << "*ptr: " << *ptr << endl;

        int *qtr = ptr; // qtr is also pointing to k like ptr. *ptr++  *qtr++  k++ all are just the same

        int b; // some garbage value as nothing is being set as value
        cout << "b:" << b << endl;
        b++;
        cout << "b:" << b << endl;

        int *m; // some garbage address will be there
        cout << "m: " << m << endl;

        cout << "*m: " << *m << endl; /*
        This can be fishy. We are trying to print value at some garbage address. May be this address doesn't
        comes into our program range.
        May be this address is a readonly memory and we are trying to tamper with it.
        But this is too risky we should not do like this.
        This can give error or may be not.
        */
        (*m)++;
        /*This means m is pointing to some random garbage address and we are changing the value at that address.
        This is not my memory and we are trying to change it. May be value will change or may be not.
        Depends on how critical location its pointing to.
        */

        cout << "*m: " << *m << endl;

        int *n = 0;
        cout << "n: " << n << endl;
        // cout << "*n: " << *n << endl;
        /*So whenever we are creating any pointer we either save some address into it and if there is nothing
        to store at current point of time then please assign it to 0(null address) means its pointing to nowhere.
        So if if you perform *n then it will give error always as there is no address here as null address value is given
        This will always give error*/
        return 0;
}