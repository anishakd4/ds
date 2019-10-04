#include<iostream>
#include<algorithm>

using namespace std;

int binarySearch(int arr[], int l, int r, int k){
    if(r >= l){
        int mid = (r+l)/2;

        if(arr[mid] == k){
            return mid;
        }else if(arr[mid] < k){
            return binarySearch(arr, mid + 1, r, k);
        }else{
            return binarySearch(arr, l, mid-1, k);
        }
    }

    return -1;
}

int findPos(int arr[], int k){
    int l=0, h=1;

    int val = arr[0];

    while(val < k){
        l = h;

        h = 2*h;

        val = arr[h];
    }

    return binarySearch(arr, l, h, k);
}

int main(){

    int arr[] = {3, 5, 7, 9, 10, 90, 100, 130,140, 160, 170};

    int answer = findPos(arr, 10);

    cout<<answer<<endl;

    return 0;
}