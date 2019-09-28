#include<iostream>

using namespace std;

int max(int a, int b){
    return (a>b)? a: b;
}

int eggDrop(int n, int k){
    int egg[n+1][k+1];

    for(int i=0; i<=k; i++){
        egg[1][i] = i;
        egg[0][i] = 0;
    }

    for(int i=0; i<=n; i++){
        egg[i][1] = 1;
        egg[i][0] = 0;
    }
    int min;

    for(int i=2; i<=n; i++){
        for(int j=2; j<=k; j++){
            egg[i][j] = INT_MAX;
            for(int x=1; x<=j; x++){
                int min = 1 + max(egg[i-1][x-1], egg[i][j-x]);
                if(egg[i][j] > min){
                    egg[i][j] = min;
                }
            }
        }
    }

    return egg[n][k];
}

int main(){
    int n=2, k=10;

    int result = eggDrop(n, k);

    cout<<result<<endl;

    return 0;
}