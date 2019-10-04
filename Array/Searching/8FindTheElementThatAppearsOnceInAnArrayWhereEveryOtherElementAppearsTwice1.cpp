#include<iostream>
#include<unordered_map>

using namespace std;

int findSingle(int arr[], int n){
    unordered_map<int, int> map;

    for(int i=0; i<n; i++){
        map[arr[i]]++;
    }

    for(auto x: map){
        if(x.second == 1){
            return x.first;
        }
    }

    return -1;
}

int main(){

    int arr[] = {2, 3, 5, 4, 5, 3, 4};

    int n = sizeof(arr)/sizeof(arr[0]);

    int answer = findSingle(arr, n);

    cout<<answer<<endl;

    return 0;
}