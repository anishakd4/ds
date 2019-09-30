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

int largestFind(int arr[], int n, int i){
    int largest = i;

    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l < n && arr[l] >  arr[largest]){
        largest = l;
    }

    if(r < n && arr[r] >  arr[largest]){
        largest = r;
    }

    return largest;
}

void heapify(int arr[], int n, int i){
    int largest = largestFind(arr, n, i);

    if(largest != i){
        swap(&arr[largest], &arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    for(int i=n/2-1; i>=0; i--){
        heapify(arr, n, i);
    }
}

int kthSmallest(int arr[], int n , int k){
    heapSort(arr, k);

    printArray(arr, n);

    for(int i=k; i<n; i++){
        if(arr[0] > arr[i]){
            swap(&arr[0], &arr[i]);
            heapify(arr, k, 0);
        }
        printArray(arr, n);
    }

    return arr[0];
}

int main(){
    int arr[] = {3, 5, 12, 7, 4, 19, 26};

    int n = sizeof(arr)/sizeof(arr[0]);

    int k = 3;

    int answer = kthSmallest(arr, n, k);

    cout<<answer<<endl;

    return 0;
}