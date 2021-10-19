#include<iostream>
#include<unordered_map>

using namespace std;

void subarrayDivisibleByK(int arr[], int n, int k){
    unordered_map<int , int> myMap;

    int s = 0, e = 0, maxs = 0, maxe = 0;

    myMap[arr[0] % k] = 0;

    for(int i=1; i<n; i++){
        int mod = arr[i] % k;

        while(myMap[k - mod] != 0){
            myMap[arr[s] % k]--;
            s++;
        }


        myMap[mod]++;
        e++;

        if((e-s) > (maxe - maxs)){
            maxe = e;
            maxs = s;
        }
    }

    cout << "The maximum size is " << maxe - maxs + 1 << " and the subarray is as follows "<<endl; 
    for (int i=maxs; i<=maxe; i++) {
        cout << arr[i] << " "; 
    }
    cout<<endl;
}

int main(){
    int k=3;
    int arr[] = {5, 10, 15, 20, 25};
    int n = sizeof(arr)/sizeof(arr[0]);

    subarrayDivisibleByK(arr, n, k);

    return 0;
}