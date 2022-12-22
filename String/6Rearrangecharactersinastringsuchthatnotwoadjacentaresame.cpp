#include<iostream>
#include<queue>
#include<unordered_map>

using namespace std;

struct Keys{
    int freq;
    char ch;

    bool operator<const Keys &k){
        
    }
}

void rearrangeString(string str){
    int n = str.length();
    unordered_map<char, int> myMap;
    
    for(int i=0; i<n; i++){
        myMap[str[i]]++;
    }

    priority_queue<
}

int main(){
    string str = "bbbaa";
    rearrangeString(str);
    return 0;
}