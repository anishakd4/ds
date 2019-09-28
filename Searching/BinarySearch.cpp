#include<iostream>

using namespace std;

int binarySearch(int arr[], int l, int r, int x){
    if(l <= r){
        int mid = (l + r)/2;

        if(arr[mid] == x){
            return mid;
        }else if(arr[mid] < x){
            return binarySearch(arr, mid+1, r, x);
        }else{
            return binarySearch(arr, l, mid - 1, x);
        }
    }

    return -1;
}

int main(){

    int arr[] = {2, 3, 4, 10, 40};

    int n = sizeof(arr)/sizeof(arr[0]);

    int x = 10;

    int answer = binarySearch(arr, 0, n-1, x);

    cout<<answer<<endl;

    return 0;
}