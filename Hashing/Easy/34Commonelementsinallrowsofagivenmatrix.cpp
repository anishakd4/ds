#include<iostream>
#include<unordered_map>

#define m 4 
#define n 5 

using namespace std;

void printCommonElements(int mat[m][n]){
    unordered_map<int, int> myMap;

    for(int i=0;i<n; i++){
        myMap[mat[0][i]] = 1;
    }

    for(int i=1; i<m; i++){
        for(int j=0; j<n; j++){
            if(myMap[mat[i][j]] == i){
                myMap[mat[i][j]] = i+1;
            }   
            if(i == m-1 && myMap[mat[i][j]] == i+1){
                cout<<mat[i][j]<<" ";
            }   
        }
    }
    cout<<endl;
}

int main(){
    int mat[m][n] = 
    { 
        {1, 2, 1, 4, 8}, 
        {3, 7, 8, 5, 1}, 
        {8, 7, 7, 3, 1}, 
        {8, 1, 2, 7, 9}, 
    };

    printCommonElements(mat);
    return 0;
}