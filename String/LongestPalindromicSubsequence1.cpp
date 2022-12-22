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

int longestPalindromeSubstring(string str, int i, int j){
    if(i == j){
        return 1;
    }

    if (str[i] == str[j] && i + 1 == j){
        return 2;
    }

    if(str[i] == str[j]){
        return longestPalindromeSubstring(str, i+1, j-1) + 2;
    }

    return max( longestPalindromeSubstring(str, i, j-1), longestPalindromeSubstring(str, i+1, j) );
}


int main()
{
    string str;
    cin >> str;
    cout << "Length is: "<< longestPalindromeSubstring(str, 0, str.length()-1)<<endl;
    return 0;
}