#include<iostream>
#include<vector>

using namespace std;

bool checkPangram(string str){
    vector<bool> mark(26, false);

    int index;
    int count = 0; 

    for(int i=0; i<str.length(); i++){
        if(str[i] >='A' && str[i] <='Z'){
            if(mark[i] == false){
                count++;
                int index = str[i] - 'A';
                mark[index] = true;
            }
        }else if(str[i] >='a' && str[i] <='z'){
            if(mark[i] == false){
                count++;
                int index = str[i] - 'a';
                mark[index] = true;
            }
        }
        if(count == 26){
            return true;
        }
    }
    if(count == 26){
        return true;
    }

    return false;
}

int main(){
    string str = "The quick brown fox jumps over the dog";

    if(checkPangram(str) == true){
        cout<<"Is panagram"<<endl;
    }else{
        cout<<"Not panagram"<<endl;
    }

    return 0;
}