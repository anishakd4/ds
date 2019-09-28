#include<iostream>

using namespace std;

int min(int a, int b){
    return (a<b)?a:b;
}

int minJump(int arr[], int n){
    int jumps[n];

    jumps[0] = 0;

    for(int i=1; i<n; i++){
        jumps[i] = INT_MAX;
        for(int j=0; j<i; j++){
            if(arr[j]+j >= i && jumps[j] != INT_MAX){
                jumps[i] = min(jumps[j] + 1, jumps[i]);
            }
        }
    }

    return jumps[n-1];
}

int main(){

    int arr[] = {1, 3, 6, 1, 0, 9}; 
    int n = sizeof(arr)/sizeof(arr[0]);

    int result = minJump(arr, n);

    cout<<result<<endl;

    return 0;
}