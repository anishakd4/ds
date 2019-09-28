#include<iostream>

using namespace std;

int max(int a, int b){
    return (a > b)? a:b;
}

int cutRod(int prices[], int n){

    if(n <= 0){
        return 0;
    }
    int min = INT_MIN;
    for(int i=0; i<n; i++){
        min = max(min, prices[i] + cutRod(prices, n-i-1));
    }

    return min;
}

int main(){

    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};

    int n = sizeof(arr)/sizeof(arr[0]);

    int result = cutRod(arr, n);

    cout<<result<<endl;
    
    return 0;
}