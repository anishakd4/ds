#include<iostream>

using namespace std;

int minInt(int a, int b, int c){
    return min(min(a, b), c);
}

int editDistance(string str1, string str2, int m, int n){
    if(m == 0){
        return n;
    }
    if(n == 0){
        return m;
    }
    if(str1[m-1] == str2[n-1]){
        return editDistance(str1, str2, m-1, n-1);
    }
    return 1 + minInt(editDistance(str1, str2, m, n-1), 
                    editDistance(str1, str2, m-1, n), 
                    editDistance(str1, str2, m-1, n-1));
}

int main(){
    string str1 = "sunday"; 
    string str2 = "saturday";

    int result = editDistance(str1, str2, str1.length(), str2.length());

    cout<<result<<endl;
    return 0;
}