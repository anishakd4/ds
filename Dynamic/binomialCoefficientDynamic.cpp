#include<iostream>

using namespace std;

int min(int a, int b) { 
    return (a < b) ? a : b; 
}

int binomialCoeff(int n, int k){
    int arr[n+1][k+1];

    for(int i=0; i<=n; i++){
        for(int j=0; j<=min(i,k); j++){
            if(j==0 || j==i){
                arr[i][j] = 1;
            }else{
                arr[i][j] = arr[i-1][j-1]+arr[i-1][j];
            }
        }
    }

    return arr[n][k];
}

int main(){
    int n=5, k=2;

    int result = binomialCoeff(n, k);

    cout<<result<<endl;

    return 0;
}