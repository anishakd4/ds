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

void grouper(vector<string> mylist){
    unordered_map<string, vector<string> > myMap;

    for(int i=0; i<mylist.size(); i++){
        string curr = mylist[i];
        string str = curr;
        sort(str.begin(), str.end());

        unordered_map<string, vector<string> >::iterator it = myMap.find(str);

        if(it != myMap.end()){
            myMap[str].push_back(curr);
        }else{
            vector<string> vec;
            vec.push_back(curr);
            myMap[str]=vec;
        }
    }

    vector<vector<string> > result;

    unordered_map<string, vector<string> >::iterator it;
    for (it = myMap.begin(); it != myMap.end(); it++) {
        vector<string> values = myMap[it->first];
        result.push_back(values);
    }

    for (int i = 0; i < result.size(); ++i)
    {
        cout << "[";
        for (int j = 0; j < result[i].size(); ++j)
        {
            cout << result[i][j] << ", ";
        }
        cout << "]";
    }
}
int main()
{
    vector<string> mylist;
    mylist.push_back("cat");
    mylist.push_back("dog");
    mylist.push_back("ogd");
    mylist.push_back("god");
    mylist.push_back("atc");
    mylist.push_back("cat");
    grouper(mylist);
    return 0;
}
