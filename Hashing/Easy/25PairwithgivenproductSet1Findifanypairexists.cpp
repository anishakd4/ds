#include<iostream>
#include<unordered_set>

using namespace std;

bool isProduct(int arr[], int arr_size, int x){
    if(arr_size < 2){
        return false;
    }

    unordered_set<int> mySet;

    for(int i=0; i<arr_size; i++){
        if(arr[i] == 0){
            if(x == 0){
                return true;
            }else{
                continue;
            }
        }

        if(x % arr[i] == 0){
            if(mySet.find(x/arr[i]) != mySet.end()){
                return true;
            }
            mySet.insert(arr[i]);
        }
    }

    return false;
}

int main(){

    int arr[] = {10, 20, 9, 40};

    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 400;
    isProduct(arr, n, x) ? cout << "Yes\n" : cout << "No\n"; 
    
    
    x = 190; 
    isProduct(arr, n, x) ? cout << "Yes\n" : cout << "No\n";

    return 0;
}