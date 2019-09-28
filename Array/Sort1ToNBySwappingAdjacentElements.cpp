#include<iostream>

using namespace std;

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

bool sortedAfterSwap(int arr[], bool b[], int n){
    int i, j;

    for(int i=0; i<n-1; i++){
        if(b[i]){
            j=i;
            while (b[j]){
                j++;
            }
            sort(arr + i, arr+j+1);
            i=j;
        }
    }

    for(int i=0; i<n; i++){
        if(arr[i] != i+1){
            return false;
        }
    }

    return true;
}

int main(){

    int arr[] = {2, 3, 1, 4, 5, 6 };

    bool b[] = {0, 1, 1, 1, 1};

    int n = sizeof(arr)/sizeof(arr[0]);

    if(sortedAfterSwap(arr, b, n)){
        cout<<"A can be sorted"<<endl;
    }else{
        cout<<"A can't be sorted"<<endl;
    }

    printArray(arr, n);

    return 0;
}