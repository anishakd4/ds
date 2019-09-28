#include<iostream>

using namespace std;

int min(int a, int b){
    return (a < b) ? a : b;
}

int minPalPartition(char str[]){
    int n = strlen(str);

    int c[n][n];
    bool p[n][n];

    for(int i=0; i<n; i++){
        p[i][i] = true;
        c[i][i] = 0;
    }

    for(int L=2; L<=n; L++){
        for(int i=0; i<n-L+1; i++){
            int j = i+L-1;
            if(L == 2){
                p[i][j] = (str[i] == str[j]);
            }else{
                p[i][j] = (str[i] == str[j] && p[i+1][j-1]);
            }

            if(p[i][j]){
                c[i][j]=0;
            }else{
                c[i][j] = INT_MAX;
                for(int m=i; m<j; m++){
                    c[i][j] = min(c[i][j], c[i][m] + c[m+1][j] + 1);
                }
            }
        }
    }

    return c[0][n-1];
}

int main(){

    char str[] = "ababbbabbababa";

    int result = minPalPartition(str);

    cout<<result<<endl;

    return 0;
}