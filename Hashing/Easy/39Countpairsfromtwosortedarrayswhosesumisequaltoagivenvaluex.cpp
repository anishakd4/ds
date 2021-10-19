#include<iostream>
#include<unordered_set>

using namespace std;

int countPairs(int arr1[], int arr2[], int m, int n, int x){
    int count = 0;

    unordered_set<int> mySet;

    for(int i=0; i<m; i++){
        mySet.insert(arr1[i]);
    }

    for(int j=0; j<n; j++){
        if(mySet.find(x - arr2[j]) != mySet.end()){
            count++;
        }
    }

    return count;
}

int main(){

    int arr1[] = {1, 3, 5, 7}; 
    int arr2[] = {2, 3, 5, 8}; 
    int m = sizeof(arr1) / sizeof(arr1[0]); 
    int n = sizeof(arr2) / sizeof(arr2[0]); 
    int x = 10; 
    cout << "Count = " << countPairs(arr1, arr2, m, n, x) << endl; 
    return 0;
}