#include<iostream>

using namespace std;

int matrixMultiply(int arr[], int n){
    int mm[n][n];

    for(int i=1; i<n; i++){
        mm[i][i] = 0;
    }

    for(int L=2; L<n; L++){
        for(int i=1; i<n-L+1; i++){
            int j = i+L-1;
            mm[i][j] = INT_MAX;
            cout<<i<<"-"<<j<<endl;
            for(int k=i; k<=j-1; k++){
                cout<<k<<" ";
                int q = mm[i][k] + mm[k+1][j]+arr[i-1]*arr[k]*arr[j];

                if(mm[i][j] > q){
                    mm[i][j] = q;
                }
            }
            cout<<endl;
        }
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            cout<<mm[i][j]<<" ";
        }
        cout<<endl;
    }

    return mm[1][n-1];
}


int main(){
    int arr[] = {1,2,3,4,3};

    int n = sizeof(arr)/sizeof(arr[0]);

    int result = matrixMultiply(arr, n);

    cout<<result<<endl;

    return 0;
}