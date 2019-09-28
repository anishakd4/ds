#include<iostream>
#include<cmath>

using namespace std;

int getMid(int s, int e) { 
    return (s + e)/2; 
} 

void printSegmentTree(int *st, int n){
    int height = ceil(log2(n));

    int max_size = 2*(pow(2, height)) - 1;

    for(int i=0; i<max_size; i++){
        cout<<st[i]<<" ";
    }

    cout<<endl;
}

int constructSegmentTreeUtil(int arr[], int ss, int se, int *st, int si){
    if(ss == se){
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss, se);

    st[si] = constructSegmentTreeUtil(arr, ss, mid, st, si*2+1) + constructSegmentTreeUtil(arr, mid+1, se, st, si*2+2);

    return st[si];  
}

int* constructSegmentTree(int arr[], int n){
    int height = ceil(log2(n));

    cout<<height<<endl;

    int max_size = 2*pow(2, height) - 1;

    cout<<max_size<<endl;

    int *st = new int[max_size];

    constructSegmentTreeUtil(arr, 0, n-1, st, 0);

    return st;
}

int main(){

    int arr[] = {1, 3, 5, 7, 9, 11};

    int n = sizeof(arr)/sizeof(arr[0]);

    int *st = constructSegmentTree(arr, n);

    printSegmentTree(st, n);

    return 0;
}