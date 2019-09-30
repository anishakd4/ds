#include<iostream>

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

void sortCustom(int arr[], int n){

    int type0 = 0;
    int type1 = n-1;
    while(type0 < type1){
        if(arr[type0] == 1){
            swap(&arr[type0], &arr[type1]);
            type1--;
        }else{
            type0++;
        }
        
    }
}

int main(){

    int arr[] = {1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1};

    int n = sizeof(arr)/sizeof(arr[0]);

    sortCustom(arr, n);

    printArray(arr, n);

    return 0;
}