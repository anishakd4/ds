#include<iostream>

using namespace std;

int findRepeating(int arr[], int n){
    int res = 0;
    for(int i=0; i<n-1; i++){
        res = res ^ arr[i] ^ (i+1); 
    }

    res = res ^ arr[n-1];

    return res;
}


int main(){

    int arr[] = { 9, 8, 2, 6, 1, 8, 5, 3, 4, 7 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << findRepeating(arr, n) <<endl; 

    return 0;
}