#include<iostream>
#include<unordered_map>

using namespace std;

void top3Repeated(int arr[], int n){
    if(n < 3){
        cout<<"Invalid input"<<endl;
    }

    unordered_map<int, int> myHash;

    for(int i=0; i<n; i++){
        myHash[arr[i]]++;
    }

    pair<int, int> x, y, z;
    x.first = y.first = z.first = INT_MIN; 

    unordered_map<int, int> :: iterator it;

    for(it = myHash.begin(); it != myHash.end(); it++){
        if(it->second > x.second){
            z = y;
            y = x;

            x.first = it->first;
            x.second = it->second;
        }else if(it->second > y.second){
            z = y;

            y.first = it->first;
            y.second = it->second;
        }
        else if(it->second > z.second){

            z.first = it->first;
            z.second = it->second;
        }
    }

    cout << "Three largest elements are " << x.first << " " << y.first  << " " << z.first <<endl; 
}

int main(){

    int arr[] = {3, 4, 2, 3, 16, 3, 15, 16, 15, 15, 16, 2, 3};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    top3Repeated(arr, arr_size);
    return 0;
}