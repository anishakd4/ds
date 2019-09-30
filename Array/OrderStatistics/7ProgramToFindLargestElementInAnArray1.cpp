#include<iostream>

using namespace std;

int largestFind(int arr[], int n){
    int max = arr[0];

    for(int i=0; i<n; i++){
        if(arr[i] >  max){
            max = arr[i];
        }
    }

    return max;
}

int main(){
    int arr[] = {10, 324, 45, 90, 9808};

    int n = sizeof(arr)/sizeof(arr[0]);

    int answer = largestFind(arr, n);

    cout<<answer<<endl;

    return 0;
}