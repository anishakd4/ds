#include<iostream>

using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int smallestFind(int arr[], int n, int i){
    int smallest = i;

    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l<n && arr[l] < arr[smallest]){
        smallest = l;
    }

    if(r<n && arr[r] < arr[smallest]){
        smallest = r;
    }

    return smallest;
}

void heapify(int arr[], int n, int i){
    int smallest = smallestFind(arr, n, i);

    if(smallest != i){
        swap(&arr[i], &arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void HeapSort(int arr[], int n){
    for(int i=n/2 - 1; i>=0; i--){
        heapify(arr, n, i);
    }

    for(int i=n-1; i>=0; i--){
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main(){

    int arr[] = {11, 3, 2, 1, 15, 5, 4, 45, 88, 96, 50, 45};

    int n = sizeof(arr)/sizeof(arr[0]);

    HeapSort(arr, n);

    printArray(arr, n);

    return 0;
}