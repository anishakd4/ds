#include<iostream>
#include<vector>
#include <queue> 

using namespace std;

void SelectActivities(vector<int> s, vector<int> f){

    vector<pair<int, int> > ans;

    priority_queue< pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > p; 

    for(int i=0; i<s.size(); i++){
        p.push(make_pair(f[i], s[i]));
    }

    pair<int, int> it = p.top();
    int start = it.second;
    int end = it.first;
    p.pop();


    ans.push_back(make_pair(start,end)); 

    while(!p.empty()){
        it = p.top();
        p.pop();

        if(it.second >= end){
            start = it.second;
            end = it.first;
            ans.push_back(make_pair(start,end)); 
        }
    }

    for(int i=0; i<s.size(); i++){
        cout<<ans[i].first<<" : "<<ans[i].second<<endl;
    }

}

int main(){

    int arr1[] = {1, 3, 0, 5, 8, 5}; 
    int arr2[] = {2, 4, 6, 7, 9, 9}; 

    int n = sizeof(arr1)/sizeof(arr1[0]);

    vector<int> s(arr1 , arr1+n);
    vector<int> f(arr2 , arr2+n);

    SelectActivities(s,f); 

    return 0;
}