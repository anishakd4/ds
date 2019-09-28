#include<iostream>

using namespace std;

int coinCount(int arr[], int m, int n){
    int table[n+1][m];

    for(int i=0; i<m; i++){
        table[0][i] = 1;
    }

    for(int i=1; i<=n; i++){
        for(int j=0; j<m; j++){
            int x = i -arr[j] >= 0 ? table[i-arr[j]][j] : 0;
            int y = j >= 1 ? table[i][j-1] : 0;
            table[i][j] = x + y;
        }
    }

    return table[n][m-1];
}

int main(){
    int arr[] = {1,2,3};

    int m = sizeof(arr)/sizeof(arr[0]);

    int result = coinCount(arr, m, 4);

    cout<<result<<endl;

    return 0;
}