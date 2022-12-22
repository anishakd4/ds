// Given a string, find the longest substring which is a palindrome. 

// Example:

// Input: Given string :”forgeeksskeegfor”, 
// Output: “geeksskeeg”

// Input: Given string :”Geeks”, 
// Output: “ee”

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

void printSubString(string str, int start, int end){
    for(int i=start; i<=end; i++){
        cout<<str[i];
    }
    cout<<endl;
}

int longestPalindromeSubstring(string str){
    int n = str.length();
    vector<vector<bool> > vec(n, vector<bool>(n, false));

    int start = 0;
    int max = 1;

    
    for(int i = 0; i < n; i++){
        vec[i][i] = true;
    }

    for(int i = 0; i < n-1; i++){
        if(str[i] == str[i + 1]){
            vec[i][i+1] = true;
            max = 2;
            start = i;
        }
    }

    for(int k=3; k<n; k++){
        for(int i=0; i<n-k+1; i++){
            if(vec[i+1][i+k-2] == true && str[i] == str[i+k-1]){
                vec[i][i+k-1] = true;
                if(max < k){
                    max = k;
                    start = i;
                }
            }
        }
    }

    cout << "Longest palindrome substring is: ";
    printSubString(str, start, start + max - 1);

    return max;
}
int main()
{
    string str;
    cin >> str;
    cout << "Length is: "<< longestPalindromeSubstring(str)<<endl;
    return 0;
}