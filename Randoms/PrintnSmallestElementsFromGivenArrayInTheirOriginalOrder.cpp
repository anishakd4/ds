#include<iostream>
#include<algorithm>

using namespace std;

void printNSMall(int arr[], int n, int k){
    int brr[n];

    for(int i=0; i<n; i++){
        brr[i] = arr[i];
    }

    sort(brr, brr + n);

    for(int i=0; i<n; i++){
        if(binary_search(brr, brr+ k, arr[i])){
            cout<<arr[i]<<" ";
        }
    }

    cout<<endl;
}

int main(){
    int arr[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};

    int n = sizeof(arr)/sizeof(arr[0]);

    int k= 5;

    printNSMall(arr, n, k);

    return 0;

}