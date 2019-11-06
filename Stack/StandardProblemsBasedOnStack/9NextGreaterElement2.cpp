#include<iostream>
#include<stack>

using namespace std;

void printNge(int arr[], int n){
    stack<int> st;

    st.push(arr[0]);

    for(int i=1; i<n; i++){
        if(st.empty()){
            st.push(arr[i]);
            continue;
        }

        while(!st.empty() && st.top() < arr[i]){
            cout<<st.top()<<" -- "<<arr[i]<<endl;
            st.pop();
        }

        st.push(arr[i]);
    }

    while (!st.empty()){
        cout<<st.top()<<" -- -1"<<endl;
        st.pop();
    }
}

int main(){

    int arr[] = {11, 13, 21, 3};

    int n = sizeof(arr)/sizeof(arr[0]);

    printNge(arr, n);

    return 0;
}