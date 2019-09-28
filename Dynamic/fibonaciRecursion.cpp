#include<iostream>
#include<algorithm>

using namespace std;

int fib(int n){
    if(n<=1){
        return n;
    }
    return fib(n-1)+fib(n-2);
}

int main(){
    long long int n;
    cin>>n;

    long long int result = fib(n);

    cout<<result<<endl;

    return 0;
}