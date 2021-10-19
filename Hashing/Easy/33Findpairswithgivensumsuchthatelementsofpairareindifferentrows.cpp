#include<iostream>
#include<unordered_map>
const int MAX = 100;

using namespace std;

void pairSum(int mat[][MAX], int n, int sum){
    unordered_map<int, int> myMap;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            myMap[mat[i][j]] = i;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int remSum = sum - mat[i][j];

            if(myMap.find(remSum) != myMap.end() && myMap[remSum] != i){
                cout<<mat[i][j]<< " : " << remSum <<endl;
                myMap.erase(remSum);
                myMap.erase(mat[i][j]);
            }
        }
    }
}

int main(){
    int n = 4, sum = 11; 
    int mat[][MAX] = {{1, 3, 2, 4}, 
                      {5, 8, 7, 6}, 
                      {9, 10, 13, 11}, 
                      {12, 0, 14, 15}}; 
    pairSum(mat, n, sum); 

    return 0;
}