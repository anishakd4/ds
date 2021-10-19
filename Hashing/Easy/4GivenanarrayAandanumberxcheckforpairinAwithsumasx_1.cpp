#include<iostream>
#include<algorithm>

using namespace std;

void printPairs(int arr[], int n, int arr_size){
    int l = 0, r = arr_size -1;

    sort(arr, arr+arr_size);

    while(l < r){
        if(arr[l] + arr[r] > n){
            r--;
        }else if(arr[l] + arr[r] < n){
            l++;
        }else{
            cout<< arr[l]<<" : "<<arr[r]<<endl;
            r--;l++;
        }
    }
}

int main(){
    int arr[] = {1, 4, 45, 6, 10, -8, 8, 8};
    int n = 16;

    int arr_size = sizeof(arr)/sizeof(arr[0]);

    printPairs(arr, n , arr_size);
    return 0;
}