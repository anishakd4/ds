#include<iostream>
#include<algorithm>

using namespace std;

int binarySearch(int arr[], int low, int high, int x){
    if(high >= low){
        int mid = (high + low)/2;

        if(arr[mid] == x) {
            return mid;
        } else if(x > arr[mid]) {
            return binarySearch(arr, (mid + 1), high, x); 
        } else{
            return binarySearch(arr, low, (mid -1), x);
        } 
    }
    return -1;
}

bool isSubset(int arr1[], int arr2[], int m, int n){
    sort(arr1, arr1+m);

    for (int i=0; i<n; i++) { 
        if (binarySearch(arr1, 0, m - 1, arr2[i]) == -1) {
            return 0;
        } 
    } 

    return 1;
}

int main(){

    int arr1[] = {11, 1, 13, 21, 3, 7}; 
    int arr2[] = {11, 3, 7, 1}; 
  
    int m = sizeof(arr1) / sizeof(arr1[0]); 
    int n = sizeof(arr2) / sizeof(arr2[0]); 
  
    if(isSubset(arr1, arr2, m, n)) 
        cout << "arr2[] is subset of arr1[] "; 
    else
        cout << "arr2[] is not a subset of arr1[] ";  

    cout<<endl;
  
    return 0; 
}