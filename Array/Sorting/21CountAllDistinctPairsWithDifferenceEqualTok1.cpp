#include<iostream>

using namespace std;

int binarySearch(int arr[], int l, int r, int x){
    if(r >= l){
        int mid = (l + r)/2;

        if(x == arr[mid]){
            return mid;
        }else if(x < arr[mid]){
            return binarySearch(arr, l, mid-1, x);
        }else{
            return binarySearch(arr, mid+1, r, x);
        }
    }

    return -1;
}

int countPairs(int arr[], int n, int k){
    int count = 0;

    sort(arr, arr+n);

    for(int i=0; i<n-1; i++){
        if(binarySearch(arr, i+1, n-1, arr[i]+k) != -1){
            count++;
        }
    }

    return count;
}

int main(){

    int arr[] = {1, 5, 3, 4, 2};

    int n = sizeof(arr)/sizeof(arr[0]);

    int k=3;

    int answer = countPairs(arr, n, k);

    cout<<answer<<endl;

    return 0;
}