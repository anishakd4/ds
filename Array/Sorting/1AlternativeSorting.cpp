#include<iostream>
#include<algorithm>

using namespace std;

void alternativeSort(int arr[], int n){
    sort(arr, arr+n);
    int i=0, j=n-1;

    while (i<j){
        cout<<arr[j]<<" ";
        cout<<arr[i]<<" ";
        i++;
        j--;
    }
    cout<<endl;
}

int main(){
    int arr[] = {1, 12, 4, 6, 7, 10};

    int n = sizeof(arr)/sizeof(arr[0]);

    alternativeSort(arr, n);

    return 0;
}