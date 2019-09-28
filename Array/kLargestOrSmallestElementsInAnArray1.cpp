#include<iostream>

using namespace std;

void kLargest(int arr[], int n, int k){
    sort(arr, arr + n);

    for(int i=n-1; i>=n-k; i--){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[] = {1, 23, 12, 9, 30, 2, 50};

    int n = sizeof(arr)/sizeof(arr[0]);

    int k = 3;

    kLargest(arr, n, k);

    return 0;
}