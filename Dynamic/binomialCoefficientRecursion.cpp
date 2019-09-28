#include<iostream>

using namespace std;

int binomialCoeff(int n, int k){
    if(k == 0 || k == n){
        return 1;
    }

    return binomialCoeff(n-1, k-1) + binomialCoeff(n-1, k);
}

int main(){
    int n=5;
    int k=2;

    int result = binomialCoeff(n, k);

    cout<<result<<endl;

    return 0;   
}