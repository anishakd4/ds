#include<iostream>

using namespace std;

int max(int a, int b){
    if(a > b){
        return a;
    }else{
        return b;
    }
}

int FindMax(int arr[], int n){
    int incl = arr[0];
    int excl = 0;

    int excl_new;
    int incl_new;

    for(int i=1; i<n; i++){
        incl_new = excl + arr[i];

        excl_new = max(incl, excl);

        excl = excl_new;
        incl = incl_new;
    }

    return max(excl, incl);
}

int main(){

    int arr[] = {5, 5, 10, 100, 10, 5};

    int n = sizeof(arr)/sizeof(arr[0]);

    int answer = FindMax(arr, n);

    cout<<answer<<endl;

    return 0;
}