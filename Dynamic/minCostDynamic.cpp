#include<iostream>

#define R 3 
#define C 3 

using namespace std;

int minInt(int a, int b, int c){
    return min(min(a, b), c);
}

int minCost(int cost[R][C], int m, int n){

    int costMat[m][n];

    costMat[0][0] = cost[0][0];

    for(int i=1; i<m; i++){
        costMat[i][0] = costMat[i-1][0]+cost[i][0]; 
    }

    for(int i=1; i<n; i++){
        costMat[0][i] = costMat[0][i-1]+cost[0][i]; 
    }

    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            costMat[i][j] = minInt(costMat[i-1][j], costMat[i][j-1], costMat[i-1][j-1]) + cost[i][j]; 
        }
    }

    return cost[m-1][n-1];
}

int main(){

    int cost[R][C] = { {1, 2, 3}, 
                      {4, 8, 2}, 
                      {1, 5, 3} }; 

    int result = minCost(cost, 2, 2);

    cout<<result<<endl;

    return 0;
}