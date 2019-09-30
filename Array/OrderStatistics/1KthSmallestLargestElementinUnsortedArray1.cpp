#include<iostream>

using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
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

int kthSmallest(int arr[], int low, int high, int k){
    if(low < high){
        int pi = partition(arr, low, high);

        if(pi == k-1){
            return arr[k-1];
        }else if(k < pi){
            kthSmallest(arr, low, pi - 1, k);
        }else{
            kthSmallest(arr, pi + 1, high, k);
        }
    }

    return arr[k-1];
}

int main(){
    int arr[] = {12, 3, 5, 7, 4, 19, 26};

    int n = sizeof(arr)/sizeof(arr[0]);
    int k=3;

    int answer = kthSmallest(arr, 0, n-1, k);

    cout<<answer<<endl;

    return 0;
}