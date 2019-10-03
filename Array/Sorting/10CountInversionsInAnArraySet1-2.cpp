#include<iostream>

using namespace std;

int merge(int arr[], int temp[], int l, int mid, int r){
    int i, j, k;

    int invCount = 0;

    i = l;
    j = mid;
    k=l;

    while(i<=mid-1 && j<=r){
        if(arr[i] < arr[j]){
            temp[k] = arr[i];
            i++;
            k++;
        }else{
            temp[k] = arr[j];
            j++;
            k++;
            invCount = invCount + (mid-i);
        }
    }

    while (i<=mid-1){
        temp[k] = arr[i];
        k++;
        i++;
    }

    while (j<=r){
        temp[k] = arr[j];
        k++; 
        j++;

    }
    
    for (i = l; i <= r; i++){
        arr[i] = temp[i];
    }

    return invCount;
}

int mergeSortUtil(int arr[], int temp[], int l, int r){
    int mid, invCount = 0;
    if(l < r){
        mid = (l+r)/2;

        invCount = mergeSortUtil(arr, temp, l, mid);
        invCount += mergeSortUtil(arr, temp, mid+1, r);

        invCount += merge(arr, temp, l, mid+1, r);
    }

    return invCount;
}

int mergeSort(int arr[], int n){

    int temp[n];

    return mergeSortUtil(arr, temp, 0, n-1);
}

int main(){
    int arr[] = {1, 20, 6, 4, 5};

    int n = sizeof(arr)/sizeof(arr[0]);

    int answer = mergeSort(arr, n);

    cout<<answer<<endl;

    return 0;
}