#include<iostream>
#include<algorithm>

using namespace std;

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

bool compare(int x, int y){
    return abs(x) < abs(y);
}

void findMinSum(int arr[], int n){
    sort(arr, arr+n, compare);
    printArray(arr, n);

    int min = INT_MAX, x, y;

    for(int i=1; i<n; i++){
        if(abs(arr[i-1] + arr[i]) < min){
            min = abs(arr[i-1] + arr[i]);
            x = i-1;
            y = i;
        }
    }
    cout<<arr[x]<<" : "<<arr[y]<<" "<<endl;
}

int main(){

    int arr[] = {1, 60, -10, 70, -80, 85};

    int n = sizeof(arr)/sizeof(arr[0]);

    findMinSum(arr, n);

    return 0;
}