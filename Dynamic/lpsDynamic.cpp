#include<iostream>

using namespace std;

int max(int a, int b){
    return (a>b)? a:b;
}

int lps(char seq[], int n){
    int m[n][n];

    for(int i=0; i<n; i++){
        m[i][i] = 1;
    }

    for(int i=2; i<=n; i++){
        for(int j=0; j<n-i+1; j++){
            int k=j+i-1;
            if(i==2 && seq[j] == seq[k]){
                m[j][k] = 2;
            }else if(seq[j] == seq[k]){
                m[j][k] = 2 + m[j+1][k-1];
            }else{
                m[j][k] = max(m[j+1][k], m[j][k-1]);
            }
        }
    }

    return m[0][n-1];
}

int main(){
    char seq[] = "GEEKSFORGEEKS";

    int n = strlen(seq);

    int result = lps(seq, n);

    cout<<result<<endl;

    return 0;
}