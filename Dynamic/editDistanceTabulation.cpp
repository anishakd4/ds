#include<iostream>
 
using namespace std;

int minInt(int a, int b, int c){
    return min(min(a, b), c);
}

int editDistance(string str1, string str2, int m, int n){

    int ed[m+1][n+1];

    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i == 0){
                ed[i][j] = j;
            }else if(j == 0){
                ed[i][j] = i;
            }else if(str1[i-1] == str2[j-1]){
                ed[i][j] = editDistance(str1, str2, i-1, j-1);
            }else{
                ed[i][j] = 1 + minInt(editDistance(str1, str2, i, j-1), 
                                    editDistance(str1, str2, i-1, j), 
                                    editDistance(str1, str2, i-1, j-1));
            }
        }
    }
    return ed[m][n];
}

int main(){
    string str1 = "sunday"; 
    string str2 = "saturday";

    int result = editDistance(str1, str2, str1.length(), str2.length());

    cout<<result<<endl;
    return 0;
}