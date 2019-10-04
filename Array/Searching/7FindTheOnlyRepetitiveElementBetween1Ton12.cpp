#include<iostream>
#include<unordered_set>

using namespace std;

int findMissing(int arr[], int n){
    unordered_set<int> set;

    for(int i=0; i<n; i++){
        if(set.find(arr[i]) != set.end()){
            return arr[i];
        }
        set.insert(arr[i]);
    }

    return -1;
}

int main(){

    int arr[] = {9, 8, 2, 6, 1, 8, 5, 3, 4, 7 };

    int n = sizeof(arr)/sizeof(arr[0]);

    int answer = findMissing(arr, n);

    cout<<answer<<endl;

    return 0;
}