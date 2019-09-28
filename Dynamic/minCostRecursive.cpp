#include<iostream>

#define R 3 
#define C 3 

using namespace std;

int minInt(int a, int b, int c){
    return min(min(a, b), c);
}

int minCost(int cost[R][C], int m, int n){
    if(n < 0 || m <0 ){
        return INT_MAX;
    }else if(n ==0 && m == 0){
        return cost[m][n];
    }else{
        return cost[m][n] + minInt(minCost(cost, m-1, n),
                                minCost(cost, m, n-1),
                                minCost(cost, m-1, n-1));
    }
}

int main(){

    int cost[R][C] = { {1, 2, 3}, 
                      {4, 8, 2}, 
                      {1, 5, 3} }; 

    int result = minCost(cost, 2, 2);

    cout<<result<<endl;

    return 0;
}