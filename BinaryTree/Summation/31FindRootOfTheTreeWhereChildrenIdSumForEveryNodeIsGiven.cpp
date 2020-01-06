#include<iostream>

using namespace std;

int findRoot(pair<int, int> arr[], int n){
    int root = 0;
    for(int i=0; i<n; i++){
        root = root + (arr[i].first - arr[i].second);
    }

    return root;
}

int main(){

    pair<int, int> arr[] = {make_pair(1, 5), make_pair(2, 0), make_pair(3, 0), make_pair(4, 0), make_pair(5, 5), make_pair(6, 5)}; 

    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<findRoot(arr, n)<<endl;

    return 0;
}