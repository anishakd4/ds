#include<iostream>

using namespace std;

int FindMin(int arr[], int l, int r){

    if(l <= r){
        int mid = (l + r)/2;

        if(arr[mid] != mid && arr[mid - 1] == mid - 1){
            return mid;
        }else if(arr[mid] == mid){
            return FindMin(arr, mid+1, r);
        }else{
            return FindMin(arr, l, mid - 1);
        }
    }
    return -1;
}

int main(){
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 10};

    int n = sizeof(arr)/sizeof(arr[0]);

    if(arr[0] != 0){
        cout<<0<<endl;
        return 0;
    }

    int answer = FindMin(arr, 1, n-1);

    cout<<answer<<endl;

    return 0;
}