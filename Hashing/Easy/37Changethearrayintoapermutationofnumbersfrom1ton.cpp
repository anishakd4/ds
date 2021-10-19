#include<iostream>
#include<unordered_map>

using namespace std;

void makePermutation(int arr[], int n){
    unordered_map<int, int> myMap;

    for(int i=0; i<n; i++){
        myMap[arr[i]]++;
    }

    int next_missing = 1;
    for(int i=0; i<n; i++){
        if(myMap[arr[i]] != 1 || arr[i] > n || arr[i] < 1){
            myMap[arr[i]]--;

            while(myMap.find(next_missing) != myMap.end()){
                next_missing++;
            }

            arr[i] = next_missing;
            next_missing++;
            myMap[next_missing] = 1;
        }
    }


}

int main(){
    int a[] = { 2, 2, 3, 3 }; 
    int n = sizeof(a) / sizeof(a[0]);

    makePermutation(a, n); 
    for (int i = 0; i < n; i++) {
        cout << a[i] << " "; 
    }
    cout<<endl;
    return 0;
}