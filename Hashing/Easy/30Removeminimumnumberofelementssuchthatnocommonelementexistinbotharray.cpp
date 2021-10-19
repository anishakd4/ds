#include<iostream>
#include<unordered_map>

using namespace std;

int minRemove(int arr1[], int arr2[], int n, int m){

    unordered_map<int, int> myMap1, myMap2;

    for(int i=0; i<n; i++){
        myMap1[arr1[i]]++;
    }

    for(int i=0; i<m; i++){
        myMap2[arr2[i]]++;
    }

    int res = 0;

    unordered_map<int, int> :: iterator it;

    for(it=myMap1.begin(); it!= myMap1.end(); it++){
        if(myMap2.find(it->first) != myMap1.end()){
            res = res + min(it->second, myMap2[it->first]);
        }
    }
    return res;
}

int main(){

    int a[] = { 1, 2, 3, 4 }; 
    int b[] = { 2, 3, 4, 5, 8 }; 

    int n = sizeof(a) / sizeof(a[0]); 
    int m = sizeof(b) / sizeof(b[0]); 
  
    cout << minRemove(a, b, n, m) <<endl; 

    return 0;
}