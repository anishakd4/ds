#include<iostream>
#include<unordered_map>
#include<stack>

using namespace std;

void nextFrequencyElement(int arr[], int n, unordered_map<int, int> freq){
    stack<int> st;
    int arr1[n];

    st.push(0);

    for(int i=1; i<n; i++){
        if(st.empty()){
            st.push(i);
            continue;
        }

        while (!st.empty() && freq[arr[st.top()]] < freq[arr[i]]){
            arr1[st.top()] = arr[i];
            st.pop();
        }

        st.push(i);    
    }

    while(!st.empty()){
        arr1[st.top()] = -1;
        st.pop();
    }

    for(int i=0; i<n; i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[]= {1, 1, 2, 3, 4, 2, 1};

    int n = sizeof(arr)/sizeof(arr[0]);

    unordered_map<int, int> map;

    for(int i=0; i<n; i++){
        map[arr[i]]++;
    }

    nextFrequencyElement(arr, n, map);

    return 0;
}