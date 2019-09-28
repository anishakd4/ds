#include<iostream>

using namespace std;

int min(int a, int b){
    return (a<b)?a:b;
}

int minJumps(int arr[], int n){
    int jumps[n];

    jumps[n-1]=0;

    for(int i=n-2; i>=0 ; i--){
        if(arr[i] == 0){
            jumps[i] = INT_MAX;
        }else if(arr[i] >= n-1-i){
            jumps[i] = 1;
        }else{
            int mini = INT_MAX;
            for(int j=i+1; j<n && j <= arr[i] + i ;j++){
                if(mini > jumps[j]){
                    mini = jumps[j];
                }
            }
            if(mini != INT_MAX){
                jumps[i] = mini + 1;
            }else{
                jumps[i] = INT_MAX;
            }
        }
    }

    return jumps[0];
}

int main(){

    int arr[] = {1, 3, 6, 1, 0, 9};

    int n = sizeof(arr)/sizeof(arr[0]);

    int result = minJumps(arr, n);

    cout<<result<<endl;

    return 0;
}