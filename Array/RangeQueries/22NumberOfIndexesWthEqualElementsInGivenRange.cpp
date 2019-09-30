#include<iostream>

using namespace std;

int answer_query(int l, int r, int arr[]){
    if(l == 0){
        return arr[r];
    }else{
        return arr[r] - arr[l-1];
    }
}

void createPrefianArray(int arr[], int n){
    if(arr[0] == arr[1]){
        arr[0] = 1;
    }else{
        arr[0] = 0;
    }
    for(int i=1; i<n-1; i++){
        if(arr[i] == arr[i+1]){
            arr[i] = arr[i-1] + 1; 
        }else{
            arr[i] = arr[i-1];
        }
    }
    arr[n-1] = arr[n-2];
}

int main(){

    int arr[] = {1, 2, 2, 2, 3, 3, 4, 4, 4 };

    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i<n; i++){
        cout<<i<<" ";
    }
    cout<<endl;

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    createPrefianArray(arr, n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int L, R; 
    L = 1; 
    R = 8; 
  
    cout << answer_query(L, R, arr) << endl; 
  
    L = 0; 
    R = 4; 
    cout << answer_query(L, R, arr) << endl; 

    return 0;
}