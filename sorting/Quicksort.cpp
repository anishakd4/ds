#include<iostream>

using namespace std;

void swap(int *a, int *b){
    int t = *a;  
    *a = *b;  
    *b = t; 
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];

    int pi = low;

    for(int i=low; i<high; i++){
        if(arr[i] < pivot){
            swap(&arr[i], &arr[pi]);
            pi++;
        }
    } 
    swap(&arr[pi], &arr[high]);
    return pi;
}

void quicksort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi-1);
        quicksort(arr, pi+1, high);
    }
}

int main(){
    int arr[] = {10, 80, 30, 90, 40, 50, 70};

    int n = sizeof(arr)/sizeof(arr[0]);

    quicksort(arr, 0, n-1);

    printArray(arr, n);

    return 0;
}