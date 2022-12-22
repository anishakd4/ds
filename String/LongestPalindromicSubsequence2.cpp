#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include <map>
#include<climits>
//climits for INT_MIN
#include <unordered_map>
using namespace std;

int longestPalindromeSubstring(string str){
    int n = str.length();
    vector<vector<int> > vec(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++){
        vec[i][i] = true;
    }

    for(int k =2; k<=n;k++){
        for(int i=0; i<n-k+1; i++){
            int j = i + k -1;
            if(str[i] == str[j] && k == 2){
                vec[i][j] = 2;
            }else if(str[i] == str[j]){
                vec[i][j] = 2 + vec[i+1][j-1];
            }else{
                vec[i][j] = max(vec[i][j-1], vec[i+1][j]);
            }
        }
    }

    return vec[0][n-1];
}
int main()
{
    string str;
    cin >> str;
    cout << "Length is: "<< longestPalindromeSubstring(str)<<endl;
    return 0;
}