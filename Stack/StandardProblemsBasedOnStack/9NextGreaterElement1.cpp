#include<iostream>

using namespace std;

void printNge(int arr[], int n){
    for(int i=0; i<n; i++){
        int next =-1;
        for(int j=i+1; j<n; j++){
            if(arr[j] >  arr[i]){
                next = arr[j];
                break;
            }
        }

        cout << arr[i] << " -- " << next << endl; 
    }
}

int main(){
    int arr[] = {11, 13, 21, 3};

    int n = sizeof(arr)/sizeof(arr[0]);

    printNge(arr, n);

    return 0;
}