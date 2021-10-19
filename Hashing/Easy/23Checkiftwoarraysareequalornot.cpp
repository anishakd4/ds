#include<iostream>
#include<unordered_map>

using namespace std;

bool areEqual(int arr1[], int arr2[], int n, int m)
{
    if(n != m){
        return false;
    }

    unordered_map<int, int> myHash;

    for(int i=0; i<n; i++){
        myHash[arr1[i]]++;
    }

    for(int i=0; i<m; i++){
        if(myHash.find(arr2[i]) == myHash.end()){
            return false;
        }else if(myHash[arr2[i]] == 0){
            return false;
        }
        myHash[arr2[i]]--;
    }

    return true;
}
int main(){

    int arr1[] = { 3, 5, 2, 5, 2 }; 
    int arr2[] = { 2, 3, 5, 5, 2 }; 
    int n = sizeof(arr1) / sizeof(int); 
    int m = sizeof(arr2) / sizeof(int); 
  
    if (areEqual(arr1, arr2, n, m)) 
        cout << "Yes"<<endl; 
    else
        cout << "No"<<endl; 

    return 0;
}