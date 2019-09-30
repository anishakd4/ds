#include<iostream>
#include<algorithm>

using namespace std;

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortInWave(int arr[], int n){
    sort(arr, arr+n);

    for(int i=0; i<n-1; i=i+2){
        swap(&arr[i], &arr[i+1]);
    }
}

int main(){

    int arr[] = {10, 90, 49, 2, 1, 5, 23};

    int n = sizeof(arr)/sizeof(arr[0]);

    sortInWave(arr, n);

    printArray(arr, n);

    return 0;
}