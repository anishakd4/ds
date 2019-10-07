#include<iostream>
#include<numeric>

using namespace std;

int findEquiliSum(int arr[], int n){
    int ans = INT_MIN;

    int sum = accumulate(arr, arr+n, 0);

    int preSum = 0;

    for(int i=0; i<n; i++){
        preSum = preSum + arr[i];

        if( preSum == sum){
            ans = max(preSum, ans);
        }

        sum = sum - arr[i];
    }

    return ans;
}

int main(){
    int arr[] = {-2, 5, 3, 1, 2, 6, -4, 2 };

    int n = sizeof(arr)/sizeof(arr[0]);

    int ans = findEquiliSum(arr, n);

    cout<<ans<<endl;

    return 0;
}