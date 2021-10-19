#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

unordered_map<string, int> sapi;

int populateInt(unordered_map<string, vector<string> > mapi, string str ){
    if(mapi.find(str) == mapi.end()){
        sapi[str] = 0;
        return 0;
    }else if(sapi.find(str) != sapi.end()){
        return sapi[str];
    }else{
        int count = 0;
        vector<string> strs =  mapi[str];
        count = strs.size();
        for(int i=0;i <strs.size(); i++){
            count = count + populateInt(mapi, strs[i]);
        }
        sapi[str] = count;
        return count;
    }
}

void populateResult(unordered_map<string, string> myMap){
    unordered_map<string, vector<string> > mapi;

    unordered_map<string, string> :: iterator it;
    for(it=myMap.begin(); it != myMap.end(); it++){
        if(it->first != it->second){
            mapi[it->second].push_back(it->first);
        }
    }

    for(it=myMap.begin(); it != myMap.end(); it++){
        populateInt(mapi, it->first);
    }

    unordered_map<string, int> :: iterator it2;
    for(it2=sapi.begin(); it2 != sapi.end(); it2++){
        cout<<it2->first<< " : "<<it2->second<<endl;
    }
    cout<<"anish2"<<endl;
}

int main(){
    unordered_map<string, string> myMap;
    myMap["A"] = "C";
    myMap["B"] = "C";
    myMap["C"] = "F";
    myMap["D"] = "E";
    myMap["E"] = "F";
    myMap["F"] = "F";

    populateResult(myMap); 
    return 0;
}