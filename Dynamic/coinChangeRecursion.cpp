#include<iostream>

using namespace std;

int coinCount(int arr[], int m, int n){

    if( n == 0){
        return 1;
    }
    if(n < 0){
        return 0;
    }
    if(m<=0 && n>=1){
        return 0;
    }

    return (coinCount(arr, m-1, n) + coinCount(arr, m, n-arr[m-1]));
}

int main(){
    int arr[] = {1,2,3};

    int size = sizeof(arr)/sizeof(arr[0]);

    int result = coinCount(arr, size, 4);

    cout<<result<<endl;

    return 0;
}