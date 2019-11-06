#include<iostream>
#include<sstream>

using namespace std;

void reverseWords(string str){
    string word;
    stringstream iss(str);

    while (iss >> word){
        reverse(word.begin(), word.end());
        cout<<word<<" ";
    }
    cout<<endl;
}

int main(){
    string str = "Geeks for Geeks";
    reverseWords(str);

    return 0;
}