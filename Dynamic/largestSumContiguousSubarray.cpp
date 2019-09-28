#include<iostream>

using namespace std;

int max(int a, int b){
    return (a>b)?a:b;
}

int min(int a, int b){
    return (a<b)?a:b;
}

int getMaxSum(int arr[], int n){

    int max_so_far = arr[0];
    int least_so_far = arr[0];

    int sum[n];
    sum[0] = arr[0];

    for(int i=1; i<n; i++){
        sum[i] = sum[i-1] + arr[i];

        max_so_far = max(sum[i] - least_so_far, max_so_far);
        least_so_far = min(least_so_far, sum[i]);
    }

    return max_so_far;
}

int main(){
    int arr[] =  {-2, -3, 4, -1, -2, 1, 5, -3};

    int n = sizeof(arr)/sizeof(arr[0]);

    int result = getMaxSum(arr, n);

    cout<<result<<endl;

    return 0;
}