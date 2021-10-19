#include<iostream>
#include<unordered_set>

using namespace std;

void printPairs(int arr[], int n, int arr_size){
    unordered_set<int> m;

    for(int i=0; i<arr_size; i++){
        if(m.find(n - arr[i]) != m.end()){
            cout << "Pair with given sum " << n << " : "<< arr[i] << ", "  << (n-arr[i]) << endl;
        }
        m.insert(arr[i]);
    }
}

int main(){
    int arr[] = {1, 4, 45, 6, 10, 8, 8 };
    int n = 16;
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    printPairs(arr, n, arr_size);
    return 0;
}