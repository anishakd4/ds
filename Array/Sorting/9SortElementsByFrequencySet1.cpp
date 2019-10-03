#include<iostream>
#include<map>
#include<unordered_map>

using namespace std;

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void sortCustom(int arr[], int n){
    unordered_map<int, int> unmap;

    for(int i=0; i<n; i++){
        unmap[arr[i]]++;
    }

    multimap<int, int> map;
    multimap<int, int>:: iterator it;

    for(int i=0; i<n; i++){
        map.insert(make_pair(unmap[arr[i]], arr[i]));
    }

    int i=0;
    for(it=map.begin(); it!= map.end(); it++){
        cout<<(*it).second<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[] = {2, 5, 2, 6, -1, 9999999, 5, 8, 8, 8};

    int n = sizeof(arr)/sizeof(arr[0]);

    sortCustom(arr, n);

    //printArray(arr, n);

    return 0;
}