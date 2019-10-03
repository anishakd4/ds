#include<iostream>

using namespace std;

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void constructArr(int arr[], int pair[], int n){
    arr[0] = (pair[0]+pair[1]-pair[n-1])/2;

    for(int i=1; i<n; i++){
        arr[i] = pair[i-1]-arr[0];
    }
}

int main(){

    int pair[] = {15, 13, 11, 10, 12, 10, 9, 8, 7, 5};

    int n=5;

    int arr[n];

    constructArr(arr, pair, n);

    printArray(arr, n);

    return 0;
}