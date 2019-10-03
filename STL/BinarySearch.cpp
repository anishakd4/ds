#include<iostream>
#include<algorithm>

using namespace std;


void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[] ={1, 5, 8, 9, 6, 7, 3, 4, 2, 0};

    int n = sizeof(arr)/sizeof(arr[0]);

    printArray(arr, n);

    sort(arr, arr+n);

    printArray(arr, n);

    if(binary_search(arr, arr+n, 2)){
        cout << "Element found in the array"<<endl; 
    }else{
        cout << "Element not found in the array"<<endl; 
    }

    if(binary_search(arr, arr+n, 10)){
        cout << "Element found in the array"<<endl; 
    }else{
        cout << "Element not found in the array"<<endl; 
    }

    return 0;
}