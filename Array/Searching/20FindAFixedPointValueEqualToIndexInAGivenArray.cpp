#include<iostream>

using namespace std;

int binarySearch(int arr[], int l, int r){
    if(r >= l){
        int mid = (l+r)/2;

        if(mid == arr[mid]){
            return mid;
        }else if(mid > arr[mid]){
            return binarySearch(arr, mid+1, r);
        }else{
            return binarySearch(arr, l, mid-1);
        }
    }
    return -1;
}

int main(){

    int arr[] = {-10, -1, 0, 3, 10, 11, 30, 50, 100};

    int n = sizeof(arr)/sizeof(arr[0]);

    int answer = binarySearch(arr, 0, n-1);

    cout<<answer<<endl;

    return 0;
}