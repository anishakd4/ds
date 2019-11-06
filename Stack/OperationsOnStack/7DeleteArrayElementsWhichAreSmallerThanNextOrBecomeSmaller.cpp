#include<iostream>
#include<stack>
#include<vector>

using namespace std;

void printVector(vector<int> vec, int m){
    cout<<"Vector: "<<endl;
    for(auto x : vec){
        cout<<x<<" ";
    }
    cout<<endl;
}

void deleteElements(int arr[], int n, int k){
    stack<int> st;
    st.push(arr[0]);

    int count = 0;

    for(int i=1; i<n; i++){
        while(!st.empty() && st.top() < arr[i] && count < k){
            st.pop();
            count++;
        }
        st.push(arr[i]);
    }

    int m = st.size();
    vector<int> v(m);
    while(!st.empty()){
        m--;
        v[m] = st.top();
        st.pop();
    }

    printVector(v, m);
}

int main(){
    int arr[] = {20, 10, 25, 30, 40};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    deleteElements(arr, n, k);
    return 0;
}