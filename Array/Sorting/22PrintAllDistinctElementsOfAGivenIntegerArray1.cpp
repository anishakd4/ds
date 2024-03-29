#include<iostream>

using namespace std;

void printDistinct(int arr[], int n){

    sort(arr, arr+n);

    for(int i=0; i<n; i++){
        while (i <n-1 && arr[i] == arr[i+1]){
            i++;
        }
        cout<<arr[i]<<" ";
    }

    cout<<endl;

}

int main(){

    int arr[] = {6, 10, 5, 4, 9, 120, 4, 6, 10};

    int n  = sizeof(arr)/sizeof(arr[0]);

    printDistinct(arr, n);

    return 0;
}