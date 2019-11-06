#include<iostream>
#include<stack>

using namespace std;

void fillNext(int next[], int arr[], int n){
    stack<int> st;

    st.push(0);

    for(int i=1; i<n; i++){
        if(st.empty()){
            st.push(i);
            continue;
        }
        while( !st.empty() && (arr[i] > arr[st.top()])){
            next[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        next[st.top()] = -1; 
        st.pop();
    }
}

void count(int arr[], int dp[], int n){
    int next[n];

    memset(next, 0, sizeof(next));

    fillNext(next, arr, n);

    for(int i=n-2; i>=0; i--){
        if(next[i] == -1){
            dp[i] = 0;
        }else{
            dp[i] = 1 + dp[next[i]];
        }
    }
}

int answerQuery(int dp[], int index) {  
    return dp[index]; 
} 

int main(){

    int arr[] = {3, 4, 2, 7, 5, 8, 10, 6};

    int n = sizeof(arr)/sizeof(arr[0]);

    int dp[n];

    count(arr, dp, n);

    cout << answerQuery(dp, 3) << endl; 
  
    cout << answerQuery(dp, 6) << endl; 
  
    cout << answerQuery(dp, 1) << endl; 

    return 0;
}