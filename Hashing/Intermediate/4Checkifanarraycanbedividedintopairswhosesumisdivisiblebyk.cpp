#include<iostream>
#include<unordered_map>

using namespace std;

bool canPairs(int arr[], int n, int k){
    unordered_map<int, int> myMap;

    int count = 0;
    for(int i=0; i<n; i++){
        myMap[arr[i] % k]++;
    }

    unordered_map<int, int> :: iterator it;
    it = myMap.begin();
    while(it != myMap.end()){
        if(myMap[it->first] == 0){
            it++;
        }else if(myMap.find(k - it->first) != myMap.end() && myMap[k - it->first] > 0 && myMap[it->first] > 0){
            count++;
            myMap[k - it->first]--;
            myMap[it->first]--;
        }else{
            it++;
        }
    }

    if(count*2 == n){
        return true;
    }else{
        return false;
    }

}

int main(){
    int arr[] = {92, 75, 65, 48, 45, 35};
    int k = 10;

    int arr_size = sizeof(arr)/sizeof(arr[0]);

    canPairs(arr, arr_size, k)? cout << "True" <<endl : cout << "False" <<endl; 

    return 0;
}