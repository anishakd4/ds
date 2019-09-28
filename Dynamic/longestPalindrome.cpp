#include<iostream>

using namespace std;

int max(int a, int b){
    return (a > b)? a:b;
}

int getLengthLongestPalindrome(char str[], int n){

    bool table[n][n];

    for(int i=0; i<n; i++){
        table[i][i] = true; 
    }

    int maxL = 1;
    int startIndex = 0;

    for(int L=2; L<=n; L++){
        for(int i=0; i<n-L+1; i++){
            int j=i+L-1;
            if(str[i] == str[j] && i+1 == j){
                table[i][j] = true;
            }else if(str[i] == str[j] && table[i+1][j-1]){
                table[i][j] = true;
            }else{
                table[i][j] = false;
            }
            if(table[i][j]){
                maxL = max(L, maxL);
                startIndex = i;
            }
        }
    }

    for(int i=startIndex; i<startIndex+maxL; i++){
        cout<<str[i];
    }
    cout<<endl;

    return maxL;
}

int main(){

    char str[] = "forgeeksskeegfor";

    int n = strlen(str);

    int result = getLengthLongestPalindrome(str, n);

    cout<<result<<endl;

    return 0;
}