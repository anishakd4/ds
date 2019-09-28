#include<iostream>
#include<algorithm>
#define NIL -1
#define MAX 100

using namespace std;

int lookupTable[MAX];

int fib(int n){
    if(lookupTable[n] == NIL){
        if(n <= 1){
            lookupTable[n] = n;
        }else{
            lookupTable[n] = fib(n-1) + fib(n-2);
        }
    }
    return lookupTable[n];
}

int main(){
    long long int n;
    cin>>n;

    for(int i=0; i<=n; i++){
        lookupTable[i] = NIL;
    }

    long long result = fib(n);

    cout<<result<<endl;

    return 0;
}