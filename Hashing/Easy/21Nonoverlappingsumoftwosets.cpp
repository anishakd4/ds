#include<iostream>
#include<unordered_map>

using namespace std;

int findSum(int arr1[], int arr2[], int n1, int n2){
    unordered_map<int, int> myHash;

    for(int i=0; i<n1; i++){
        myHash[arr1[i]]++;
    }
    for(int i=0; i<n2; i++){
        myHash[arr2[i]]++;
    }

    int res = 0;
    unordered_map<int, int> :: iterator it;
    for(it=myHash.begin(); it != myHash.end(); it++){
        if(it->second == 1){
            res = res + it->first;
        }
    }

    return res;
}

int main(){

    int a[] = { 5, 4, 9, 2, 3 }; 
    int b[] = { 2, 8, 7, 6, 3 };

    int n1 = sizeof(a)/sizeof(a[0]);
    int n2 = sizeof(b)/sizeof(b[0]);

    cout<<findSum(a, b, n1, n2)<<endl;
    return 0;
}