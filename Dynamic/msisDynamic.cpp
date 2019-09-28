#include<iostream>

using namespace std;

int max(int a, int b){
    return (a>b) ? a:b;
}

int msis(int arr[], int n){

    int m[n];

    for(int i=0; i<n; i++){
        m[i] = arr[i];
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[j] < arr[i] && m[i] < m[j] + arr[i]){
                m[i] = m[j] + arr[i]; 
            }
        }  
    }

    int min = INT_MIN;
    for(int i=0; i<n; i++){
        min = max(min, m[i]);
    }

    return min;
}

int main(){
    int arr[] = {1, 101, 2, 3, 100, 4, 5}; 

    int n = sizeof(arr)/sizeof(arr[0]);

    int result = msis(arr, n);

    cout<<result<<endl;
    
    return 0;
}