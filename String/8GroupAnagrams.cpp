#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <climits>
// climits for INT_MIN
#include <unordered_map>
using namespace std;

void grouper(vector<string> mylist)
{
    map<map<char, int>, vector<string> > myMap;

    for (int i = 0; i < mylist.size(); i++)
    {
        string curr = mylist[i];
        map<char, int> frequencyMap;
        for (int j = 0; j < curr.length(); j++)
        {
            map<char, int>::iterator it = frequencyMap.find(curr[j]);
            if (it != frequencyMap.end())
            {
                frequencyMap[curr[j]]++;
            }
            else
            {
                frequencyMap[curr[j]] = 1;
            }
        }

        map<map<char, int>, vector<string> >::iterator im = myMap.find(frequencyMap);
        if (im != myMap.end())
        {
            vector<string> temp_my_list;
            temp_my_list.push_back(curr);
            myMap[frequencyMap].push_back(curr);
        }
        else
        {
            myMap[frequencyMap].push_back(curr);
        }
    }

    vector<vector<string> > result;

    for (auto it = myMap.begin();
         it != myMap.end(); ++it)
    {
        result.push_back(it->second);
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