#include<iostream>

using namespace std;

void printArray(int arr[], int n){
    for(int i=0;i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int findMaxEqulibriumSum(int arr[], int n){
    int preSum[n];
    preSum[0] = arr[0];
    for(int i=1; i<n; i++){
        preSum[i] = preSum[i-1] + arr[i]; 
    }
    printArray(preSum, n);

    int ans = INT_MIN;

    int suffSum[n];
    suffSum[n-1] = arr[n-1];
    for(int i=n-2; i>=0; i--){
        suffSum[i] = suffSum[i+1] + arr[i]; 
        if (suffSum[i] == preSum[i]) {
            ans = max(ans, preSum[i]); 
        }
    }

    printArray(suffSum, n);

    return ans;
}

int main(){

    int arr[] = {-2, 5, 3, 1, 2, 6, -4, 2};

    int n = sizeof(arr)/sizeof(arr[0]);

    printArray(arr, n);

    int ans = findMaxEqulibriumSum(arr, n);

    cout<<ans<<endl;

    return 0;
}