#include<iostream>

using namespace std;

bool increasing(int arr[], int n){
    for(int i=0; i<n-1; i++){
        if(arr[i] > arr[i+1]){
            return false;
        }
    }

    return true;
}

bool decreasing(int arr[], int n){
    for(int i=0; i<n-1; i++){
        if(arr[i] < arr[i+1]){
            return false;
        }
    }

    return true;
}

int shortestUnsortedArray(int arr[], int n){
    if(increasing(arr, n) || decreasing(arr, n)){
        return 0;
    }else{
        return 3;
    }
    
}

int main(){

    int arr[] = {7, 9, 10, 8, 11};

    int n = sizeof(arr)/sizeof(arr[0]);

    int answer = shortestUnsortedArray(arr, n);

    cout<<answer<<endl;

    return 0;
}