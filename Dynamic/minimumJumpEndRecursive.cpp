#include<iostream>

using namespace std;

int minjump(int arr[], int l, int h){
    if(h == l){
        return 0;
    }

    if(arr[l] == 0){
        return INT_MAX;
    }

    int mini = INT_MAX;

    for(int i=l+1; i<=(l+arr[l]) && i<=h; i++){
        int jumps = minjump(arr, i, h);
        if(jumps != INT_MAX){
            mini = min(mini, jumps+1);
        }
    }

    return mini;

}

int main(){
    int arr[] = {1, 3, 6, 3, 2, 3, 6, 8, 9, 5}; 

    int n = sizeof(arr)/sizeof(arr[0]);

    int result = minjump(arr, 0, n-1);

    cout<<result<<endl;
    return 0;
}