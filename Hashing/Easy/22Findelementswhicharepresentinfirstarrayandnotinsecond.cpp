#include<iostream>
#include<unordered_set>

using namespace std;

void findMissing(int arr1[], int arr2[], int n1, int n2){
    unordered_set<int> mySet;
    for(int i=0; i<n2; i++){
        mySet.insert(arr2[i]);
    }
    for(int j=0; j<n1; j++){
        if(mySet.find(arr1[j]) == mySet.end()){
            cout<< arr1[j]<<" ";
        }
    }
    cout<<endl;
}

int main(){
    int arr1[] = {1, 2, 6, 3, 4, 5};
    int arr2[] = {2, 4, 3, 1, 0};

    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    findMissing(arr1, arr2, n1 , n2);
    return 0;
}