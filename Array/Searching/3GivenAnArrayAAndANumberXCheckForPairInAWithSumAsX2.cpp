#include<iostream>
#include<unordered_set>

using namespace std;

void printPairs(int arr[], int n, int x){
    unordered_set<int> seti;

    for(int i=0; i<n; i++){
        int temp = x - arr[i];

        if(seti.find(temp) != seti.end()){
            cout << "Pair with given sum " << x << " is (" << arr[i] << ", " << temp << ")" << endl; 
        }
        seti.insert(arr[i]); 
    }
}

int main(){
    int arr[] = {1, 4, 45, 6, 10, 8};

    int x = 16;

    int n = sizeof(arr)/sizeof(arr[0]);

    printPairs(arr, n, x);

    return 0;

}