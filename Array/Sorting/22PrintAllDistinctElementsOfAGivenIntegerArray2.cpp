#include<iostream>
#include<unordered_set>

using namespace std;

void printDistinct(int arr[], int n){
    unordered_set<int> set;

    for(int i=0; i<n; i++){
        if(set.find(arr[i]) == set.end()){
            set.insert(arr[i]);
            cout<<arr[i]<<endl;
        }
    }
}

int main(){
    int arr[] = {10, 5, 3, 4, 3, 5, 6};

    int n = sizeof(arr)/sizeof(arr[0]);

    printDistinct(arr, n);

    return 0;
}