#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

unordered_map<int, int> m2; 

bool sortByVal(const pair<int, int> &a, const pair<int, int> &b){
    if(a.second == b.second){
        return m2[a.first] < m2[b.first];
    }

    return a.second > b.second;
}

void sortByFreq(int arr[], int n){
    unordered_map<int, int> m1;
    vector<pair<int ,int> > v;

    for(int i=0; i<n; i++){
        m1[arr[i]]++;

        if(m2.find(arr[i]) == m2.end()){
            m2[arr[i]] = i;
        }
    }

    unordered_map<int, int> :: iterator it;
    for(it=m1.begin(); it!= m1.end(); it++){
        v.push_back(make_pair(it->first, it->second));
    }

    sort(v.begin(), v.end(), sortByVal);

    for (int i = 0; i < v.size(); ++i)  {
        for (int j = 0; j < v[i].second; ++j)  {
            cout << v[i].first << " ";  
        }
    }
    cout<<endl;
}

int main(){

    int arr[] = {2, 5, 2, 6, -1, 9999999, 5, 8, 8, 8};
    int arr_size = sizeof(arr)/sizeof(arr_size);

    sortByFreq(arr, arr_size);

    return 0;
}