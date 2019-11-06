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

void printStack(stack<int> st){
    cout<<"Stack: "<<endl;
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

stack<int> sortStack(stack<int> st){
    stack<int> temp;

    while (!st.empty()){
        int x = st.top();
        st.pop();

        while (!temp.empty() && temp.top() > x){
            st.push(temp.top()); 
            temp.pop();
        }
        
        temp.push(x);
    }
    
    return temp;
}

void sortArray(int arr[], int n){
    stack<int> st;

    for(int i=0; i<n; i++){
        st.push(arr[i]);
    }

    stack<int> temp = sortStack(st);

    printStack(temp);

    for(int i=0; i<n; i++){
        arr[i] = temp.top();
        temp.pop();
    }
}

int main(){
    int arr[] = {10, 5, 15, 45};

    int n = sizeof(arr)/sizeof(arr[0]);

    printArray(arr, n);

    sortArray(arr, n);

    printArray(arr, n);

    return 0;
}