#include<iostream>

#define R 6
#define C 5

using namespace std;

int mini(int a, int b, int c){
    int d = min(a, b);
    return min(d, c);
}

int printMaxSquare(int M[R][C]){
    int S[R][C];

    for(int i=0; i<R; i++){
        S[i][0] = M[i][0];
    }

    for(int i=0; i<C; i++){
        S[0][i] = M[0][i];
    }

    for(int i=1; i<R; i++){
        for(int j=1; j<C; j++){
            if(M[i][j] == 1){
                S[i][j] = mini(S[i-1][j], S[i][j-1], S[i-1][j-1]) + 1;
            }else{
                S[i][j] = 0;
            }
        }
    }

    int maxi = S[0][0];
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            maxi = max(maxi, S[i][j]);
        }
    }

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cout<<S[i][j]<<" ";
        }
        cout<<endl;
    }

    return maxi;
}

int main(){
    int M[R][C] = {{0, 1, 1, 0, 1},  
                    {1, 1, 0, 1, 0},  
                    {0, 1, 1, 1, 0},  
                    {1, 1, 1, 1, 0},  
                    {1, 1, 1, 1, 1},  
                    {0, 0, 0, 0, 0}};

    int result = printMaxSquare(M);

    cout<<result<<endl;

    return 0;
}