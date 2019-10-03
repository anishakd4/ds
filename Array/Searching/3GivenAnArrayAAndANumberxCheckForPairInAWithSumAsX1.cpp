#include<iostream>

using namespace std;

bool hasArrayTwoCandidates(int arr[], int n, int x){
    int l, r;
    l=0;
    r=n-1;

    sort(arr, arr+n);

    while(l < r){
        if(arr[l] + arr[r] == x){
            return 1;
        }else if(arr[l] + arr[r] < x){
            l++;
        }else{
            r--;
        }
    }

    return 0;
}

int main(){
    int arr[] = {1, 4, 45, 6, 10, -8};

    int n = sizeof(arr)/sizeof(arr[0]);

    int x = 16;

    if(hasArrayTwoCandidates(arr, n , x)){
        cout<<"Array has two elements with given sum"<<endl;
    }else{
        cout<<"Array doesn't has two elements with given sum"<<endl;
    }

    return 0;
}