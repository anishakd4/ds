#include<iostream>

using namespace std;

void printLeaders(int arr[], int n){
    int max = INT_MIN;

    for(int i=n-1; i>=0; i--){
        if(max < arr[i]){
            max = arr[i];
            cout<<arr[i]<<" ";
        }
    }
    cout<<endl;
}

int main(){
    int arr[] = {16, 17, 4, 3, 5, 2};

    int n = sizeof(arr)/sizeof(arr[0]);

    printLeaders(arr, n);

    return 0;
}