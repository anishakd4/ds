#include<iostream>

#define INF INT_MAX

using namespace std;

int printSolution (int p[], int n)  {  
    int k;  
    if (p[n] == 1)  
        k = 1;  
    else
        k = printSolution (p, p[n]-1) + 1;  
    cout<<"Line number "<<k<<": From word no. "<<p[n]<<" to "<<n<<endl;  
    return k;  
}  

void solveWordWrap(int l[], int n, int M){

    int extras[n+1][n+1];

    int lc[n+1][n+1];

    int c[n+1];

    int p[n+1];

    for(int i=1; i<=n; i++){
        extras[i][i] = M - l[i-1];
        for(int j=i+1; j<=n; j++){
            extras[i][j] = extras[i][j-1] - l[j-1] - 1;
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            if(lc[i][j] < 0){
                lc[i][j] = INF;
            }else if(j == n && extras[i][j] >= 0){
                lc[i][j] = 0;
            }else{
                lc[i][j] = extras[i][j]*extras[i][j];
            }
        }
    }

    c[0] = 0;
    for(int i=1; i<=n; i++){
        c[i] = INF;
        for(int j=1; j<=i; j++){
            if(c[j-1] != INF && lc[i][j] != INF && c[i] > c[i-1] + lc[i][j]){
                c[i] = c[i-1] + lc[i][j];
                p[i] = j;
            }
        }
    }
    printSolution(p, n);
}


int main(){

    int l[] = {3, 2, 2, 5};  

    int n = sizeof(l)/sizeof(l[0]);

    int M = 6;

    solveWordWrap(l, n, M);
}