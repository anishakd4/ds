#include<iostream>
#include<queue>

using namespace std;

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void sortK(int arr[], int n, int k){
    priority_queue<int, vector<int>, greater<int> > pQueue(arr, arr+k+1);

    int j=0;
    for(int i=k+1; i<n; i++){
        arr[j] = pQueue.top();
        j++;
        pQueue.pop();
        pQueue.push(arr[i]);
    }

    while (!pQueue.empty()){
        arr[j] = pQueue.top();
        j++;
        pQueue.pop();
    }
}

int main(){

    int arr[] = {2, 6, 3, 12, 56, 8};

    int k = 3;

    int n = sizeof(arr)/sizeof(arr[0]);

    sortK(arr, n, k);

    printArray(arr, n);

    return 0;
}