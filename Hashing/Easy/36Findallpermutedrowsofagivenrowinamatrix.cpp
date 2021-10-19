#include<iostream>
#include<unordered_set>
#define MAX 100 

using namespace std;

void permutatedRows(int mat[][MAX], int m, int n, int r){

    unordered_set<int> mySet;
    for(int i=0;i <n; i++){
        mySet.insert(mat[r][i]);
    }

    for(int i=0; i<m; i++){
        if(i == r){
            continue;
        }

        int j=0;
        for(j=0; j<n; j++){
            if(mySet.find(mat[i][j]) == mySet.end()){
                break;
            }
        }

        if(j != n){
            continue;
        }

        cout<< i <<endl;
    }

}

int main(){

    int m = 4, n = 4,r = 3; 
    int mat[][MAX] = {{3, 1, 4, 2}, 
                      {1, 6, 9, 3}, 
                      {1, 2, 3, 4}, 
                      {4, 3, 2, 1}}; 
    permutatedRows(mat, m, n, r); 

    return 0;
}