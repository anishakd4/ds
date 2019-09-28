#include<iostream>
#include<queue>

using namespace std;

int kThLargestSum(int arr[], int n, int k){
    int sum[n];
    sum[0] = arr[0];
    for(int i=1; i<n; i++){
        sum[i] = sum[i-1] + arr[i];
    }

    priority_queue<int, vector<int>, greater<int> > pQueue;

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){

            int x;
            if(i == j){
                x = arr[i];
            }else{
                x = sum[j] - sum[i];
            }

            if(pQueue.size() < k){
                pQueue.push(x);
            }else{
                if(pQueue.top() < x){
                    pQueue.pop();
                    pQueue.push(x);
                }
            }
        }
    }

    return pQueue.top();
}

int main(){
    int arr[] = {10, -10, 20, -40};

    int n = sizeof(arr)/sizeof(arr[0]);

    int k = 6;

    int answer = kThLargestSum(arr, n, k);

    cout<<answer<<endl;

    return 0;
}