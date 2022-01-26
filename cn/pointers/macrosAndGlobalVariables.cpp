#include <iostream>//preprocessor directive. This works before compile. I will copy all the this iostream code here before compile to compile
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
#define PI 3.14
//its going to work on before compile. Its going to find PI all over the code and replace it with 3.14
//compiler will see 3.14 at all the places of PI

int a;
//global variable
//bad pactice, better to share references and should be handled properly

void g(){
    a++;
    cout<<a<<endl;
}

void f(){
    cout<<a<<endl;
    a++;
    g();
}
int main()
{
    int r;
    cin >> r;
    //double pi = 3.14;
    //1st problem if someone changes pi at someplace then, whole code will break
    //2nd problem is this extras storage
    cout << PI * r * r << endl;

    //pi = pi + 1;
    //if anyone by mistake does this code then it will break the code

    a = 10;
    f();
    cout<<a<<endl;
    return 0;
}