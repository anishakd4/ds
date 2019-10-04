#include<iostream>
#include<numeric>

using namespace  std;

int findRepeating(int arr[], int n){

    return accumulate(arr, arr+n, 0) - ((n-1) * n/2);
}

int main(){

    int arr[] = {1, 5, 1, 2, 3, 4};

    int n = sizeof(arr)/sizeof(arr[0]);

    int answer = findRepeating(arr, n);

    cout<<answer<<endl;

    return 0;
}
