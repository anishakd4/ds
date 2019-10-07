#include<iostream>

using namespace std;

int ceilSearch(int arr[], int l, int r, int x){

    cout<<l<<" : "<<r<<endl;
    int mid = (l + r)/2;
    cout<<mid<<endl;

    if(x <= arr[l]){
        return l;
    }

    if(x >= arr[r]){
        return -1;
    }

    if(arr[mid] == x){
        return mid;
    }

    if(x > arr[mid]){
        return ceilSearch(arr, mid+1, r, x);
    }else{
        if((mid - 1 >= l) && (x > arr[mid - 1])) {
            return mid; 
        }else{
            return ceilSearch(arr, l, mid - 1, x);
        }
    }
}

int main(){

    int arr[] = {1, 2, 8, 10, 10, 12, 19};

    int n = sizeof(arr)/sizeof(arr[0]);

    int x = 20; 

    int ans = ceilSearch(arr, 0, n-1, x);

    cout<<ans<<endl;

    return 0;
}