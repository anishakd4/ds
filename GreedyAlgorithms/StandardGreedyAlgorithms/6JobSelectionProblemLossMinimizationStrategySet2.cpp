#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>

using namespace std;

void optimum_sequence_jobs(vector<int> vec, double p){
    sort(vec.begin(), vec.end());

    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    double res = 0; 
    for(int i=vec.size(); i>=1; i--){
        res = res + pow(1-p, vec.size()-i)*vec[i-1];
    }
    cout<<res<<endl;
}

int main(){

    int arr[] = {3, 5, 4, 1, 2, 7, 6, 8, 9, 10};
    int n = sizeof(arr)/sizeof(arr[0]);

    vector<int> vec (arr, arr+n);
    double P = 0.10; 
    optimum_sequence_jobs(vec, P);
    return 0;
}