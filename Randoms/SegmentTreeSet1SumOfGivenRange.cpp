#include<iostream>
#include<cmath>

using namespace std;

void updateValueUtil(int *st, int ss, int se, int i, int diff, int si){
    if(i<ss || i > se){
        return;
    }
    st[si] += diff;
    if(se != ss){
        int mid = (ss + se)/2;
        updateValueUtil(st, ss, mid, i, diff, 2*si + 1);
        updateValueUtil(st, mid + 1, se, i, diff, 2*si + 2);
    }
}

void updateValue(int arr[], int *st, int n, int i, int new_val){
    if(i<0 || i>n-1){
        return;
    }

    int diff = new_val - arr[i];

    arr[i] = new_val; 

    updateValueUtil(st, 0, n-1, i, diff, 0);
}

int getSumUtil(int *st, int ss, int se, int qs, int qe, int si){
    if(ss > qe || se < qs){
        return 0;
    }

    if(qs <= ss && se <= qe){
        return st[si];
    }

    int mid = (ss + se)/2;

    return getSumUtil(st, ss, mid, qs, qe, 2*si + 1) + getSumUtil(st, mid + 1, se, qs, qe, 2*si + 2);
}

int getSum(int *st, int n, int l, int r){
    if(l < 0 || r > n-1 || l > r){
        return -1;
    }

    return getSumUtil(st, 0, n-1, l, r, 0);
}

void printSegmentTree(int *st, int n){
    int height = ceil(log2(n));

    int max_size = 2*(pow(2, height)) - 1;

    for(int i=0; i<max_size; i++){
        cout<<st[i]<<" ";
    }

    cout<<endl;
}

int createSegmentTreeUtil(int arr[], int ss, int se, int *st, int si){
    if(ss == se){
        st[si] = arr[ss];
        return arr[ss];
    }

    int mid = (ss + se)/2;
    st[si] = createSegmentTreeUtil(arr, ss, mid, st, 2*si + 1) + createSegmentTreeUtil(arr, mid + 1, se, st, 2*si + 2);

    return st[si];
}

int* createSegmentTree(int arr[], int n){
    int height = ceil(log2(n));

    int max_size = 2*pow(2, height) - 1;

    int *st = new int[max_size];

    createSegmentTreeUtil(arr, 0, n-1, st, 0);

    return st;
}

int main(){
    int arr[] = {1, 3, 5, 7, 9, 11};

    int n = sizeof(arr)/sizeof(arr[0]);

    int *st = createSegmentTree(arr, n);

    printSegmentTree(st, n);

    cout<<"Sum of values in given range = "<<getSum(st, n, 1, 3)<<endl;  

    updateValue(arr, st, n, 1, 10);

    cout<<"Sum of values in given range = "<<getSum(st, n, 1, 3)<<endl;  

    return 0;
}