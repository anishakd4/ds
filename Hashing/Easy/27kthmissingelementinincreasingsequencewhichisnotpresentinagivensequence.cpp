#include<iostream>
#include<unordered_set>

using namespace std;

int findK(int arr1[], int arr2[], int k, int n1, int n2){
    unordered_set<int> mySet;

    for(int i=0; i<n2; i++){
        mySet.insert(arr2[i]);
    }

    int missing = 0;

    for(int i=0; i<n1; i++){
        if(mySet.find(arr1[i]) == mySet.end()){
            missing++;
        }
        if(missing == k){
            return arr1[i];
        }
    }
    return -1;
}

int main(){

    int a[] = { 0, 2, 4, 6, 8, 10, 12, 14, 15 }; 
    int b[] = { 4, 10, 6, 8, 12 }; 
    int n1 = sizeof(a) / sizeof(a[0]); 
    int n2 = sizeof(b) / sizeof(b[0]); 
  
    int k = 3; 
    cout << findK(a, b, k, n1, n2) <<endl; 

    return 0;
}