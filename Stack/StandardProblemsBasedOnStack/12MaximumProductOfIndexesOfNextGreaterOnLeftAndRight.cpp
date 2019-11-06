#include<iostream>
#include<stack>

using namespace std;

void printArray(int arr[], int n){
    cout<<"Array: "<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void leftGreater(int l[], int arr[], int n){
    stack<int> st;

    st.push(n-1);

    for(int i=n-2; i>=0; i--){
        if(st.empty()){
            st.push(i);
            continue;
        }

        while (!st.empty() && arr[i]> arr[st.top()]){
            l[st.top()] = i+1;
            st.pop();
        }

        st.push(i);
    }
    while (!st.empty()){
        l[st.top()] = 0;
        st.pop();
    }
}

void rightGreater(int r[], int arr[], int n){
    stack<int> st;

    st.push(0);

    for(int i=1; i<n; i++){
        if(st.empty()){
            st.push(i);
            continue;
        }

        while (!st.empty() && arr[i]> arr[st.top()]){
            r[st.top()] = i+1;
            st.pop();
        }

        st.push(i);
    }
    while (!st.empty()){
        r[st.top()] = 0;
        st.pop();
    }
}

int LRProduct(int arr[], int n){
    int rGreater[n];
    int lGreater[n];

    rightGreater(rGreater, arr, n);

    leftGreater(lGreater, arr, n);

    printArray(rGreater, n);

    printArray(lGreater, n);

    int ans = -1;
    for(int i=0; i<n; i++){
        ans = max(ans, lGreater[i] * rGreater[i]);
    }

    return ans;
}

int main(){
    int arr[] = {5, 4, 3, 4, 5};

    int n = sizeof(arr)/sizeof(arr[0]);

    cout << LRProduct(arr, n)<<endl;

    return 0;
}