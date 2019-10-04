#include<iostream>

using namespace std;

int findSingle(int arr[], int n){
    int res = 0;

    for(int i=0; i<n; i++){
        res = res ^ arr[i];
    }

    return res;
}

int main(){

    int arr[] = {2, 3, 5, 4, 5, 3, 4};

    int n = sizeof(arr)/sizeof(arr[0]);

    int answer = findSingle(arr, n);

    cout<<answer<<endl;

    return 0;
}