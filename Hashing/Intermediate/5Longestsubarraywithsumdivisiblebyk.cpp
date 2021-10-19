#include<iostream>
#include<unordered_map>

using namespace std;

int longSubarrWthSumDivByK(int arr[], int n, int k){
    unordered_map<int, int> myMap;

    int mod_arr[n], max = 0;
    int curr_sum = 0;

    for(int i=0; i<n; i++){
        curr_sum = curr_sum + arr[i];
        mod_arr[i] = curr_sum % k;
    }

    for(int i=0; i<n; i++){
        if(mod_arr[i] == 0){
            max = i+1;
        }else if(myMap.find(mod_arr[i]) == myMap.end()){
            myMap[mod_arr[i]] = i;
        }else{
            if( max < (i - myMap[mod_arr[i]])){
                max = (i - myMap[mod_arr[i]]);
            }
        }
    }

    return max;
}

int main(){

    int arr[] = {2, 7, 6, 1, 4, 5};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    int k=3;

    cout << "Length = " << longSubarrWthSumDivByK(arr, arr_size, k) <<endl; 
    return 0;
}