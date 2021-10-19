#include<iostream>
#include<unordered_map>

using namespace std;

int countQuadruples(int arr1[], int arr2[], int arr3[], int arr4[], int n, int x){
    int count = 0;

    unordered_map<int, int> myMap;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            myMap[arr1[i] + arr2[j]]++;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(myMap.find(x - (arr3[i] + arr4[j])) != myMap.end()){
                count++;
            }
        }
    }

    return count;
}

int main(){

    int arr1[] = {1, 4, 5, 6};
    int arr2[] = {2, 3, 7, 8};
    int arr3[] = {1, 4, 6, 10};
    int arr4[] = {2, 4, 7, 8};

    int n = sizeof(arr1)/sizeof(arr1[0]);
    int x = 30; 
    cout << "Count = " << countQuadruples(arr1, arr2, arr3, arr4, n, x) << endl;

    return 0;
}