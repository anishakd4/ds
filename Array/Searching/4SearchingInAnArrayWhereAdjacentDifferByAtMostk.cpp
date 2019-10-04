#include<iostream>

using namespace std;

int findIndex(int arr[], int n, int x, int k){
    int i=0;

    while(i<n){
        if(arr[i] == x){
            return i;
        };

        i = i + max(1, abs(x-arr[i])/k);
    }

    return -1;
}

int main(){

    int arr[] = {2, 4, 5, 7, 7, 6};

    int x = 6;

    int k = 2;

    int n = sizeof(arr)/sizeof(arr[0]);

    int answer = findIndex(arr, n, x, k);

    cout<<answer<<endl;
    
    return 0;
}