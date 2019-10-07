#include<iostream>
#include<algorithm>

using namespace std;

int findPeak(int arr[], int l, int r, int n){
    int mid = (l+r)/2;

    if((mid == 0 && arr[mid] > arr[mid+1]) || (mid == n-1 && arr[mid] > arr[mid-1]) || (arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1])){
        return mid;
    }else if(mid >0 && arr[mid-1] > arr[mid]){
        return findPeak(arr, l, mid-1, n);
    }else {
        return findPeak(arr, mid+1, r, n);
    }
}

int main(){

    int arr[] = {1, 3, 20, 4, 1, 0};

    int n = sizeof(arr)/sizeof(arr[0]);

    int answer = findPeak(arr, 0, n-1, n);

    cout<<answer<<endl;

    return 0;
}