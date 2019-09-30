#include<iostream>
#include<algorithm>

using namespace std;

int countPairs(int arr[], int n, int mid){
    int ans = 0;
    for(int i=0; i<n; i++){
        ans = ans + upper_bound(arr + i, arr + n, arr[i] + mid) - (arr + i + 1);
    }

    return ans;
}

int kthDiff(int arr[], int n, int k){
    sort(arr, arr+n);

    int high = arr[n-1] - arr[0];
    int low = arr[1] - arr[0];
    for(int i=i; i<n-1; i++){
        if(arr[i+1] - arr[i] < low){
            low = arr[i+1] - arr[i];
        }
    }

    while(low < high){
        int mid = (low+high) / 2;
        if(countPairs(arr, n, mid) < k){
            low = mid + 1;
        }else{
            high = mid;
        }
    }

    return low;
}

int main(){

    int k = 3;

    int arr[] = {1, 2, 3, 4};

    int n = sizeof(arr)/sizeof(arr[0]);

    int answer = kthDiff(arr, n, k);

    cout<<answer<<endl;

    return 0;
}