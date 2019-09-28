#include<iostream>

using namespace std;

int max(int a, int b){
    return (a > b)? a: b;
}

int eggDrop(int n, int k){
    if(k == 1 || k == 0){
        return k;
    }

    if(n == 1){
        return k;
    }

    int min = INT_MAX;

    for(int i=1; i<=k; i++){
        int y = max(eggDrop(n-1, i-1), eggDrop(n, k-i));
        if(y < min){
            min = y;
        }
    }

    return min + 1;
}

int main(){
    int n=2, k=10;

    int result = eggDrop(n, k);

    cout<<result<<endl;

    return 0;
}