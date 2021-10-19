#include<iostream>
#include<vector>

using namespace std;

string missingChars(string str){
    vector<bool> mark(26, false);

    for(int i=0; i<str.length(); i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            mark[str[i] - 'A'] = true;
        }else if(str[i] >= 'a' && str[i] <= 'z'){
            mark[str[i] - 'a'] = true;
        }
    }

    string res;
    for(int i=0; i<26; i++){
        if(mark[i] == false){
            res = res + ((char) (i+'a'));
        }
    }

    return res;
}

int main(){

    string str = "The quick brown fox jumps over the dog";

    cout << missingChars(str)<<endl; 
    return 0;
}