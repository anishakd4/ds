#include<iostream>

using namespace std;

int matrixMultiply(int arr[], int i, int j){
    if(i == j){
        return 0;
    }

    int k;
    int min = INT_MAX;
    int count;

    for(int k=i; k<j; k++){
        count = matrixMultiply(arr, i, k) + matrixMultiply(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];

        if(count < min){
            min = count;
        }
    }

    return min;
}

int main(){

    int arr[] = {1, 2, 3, 4, 3};

    int n = sizeof(arr)/sizeof(arr[n]);

    int result = matrixMultiply(arr, 1, n-1);

    cout<<result<<endl;

    return 0;
}