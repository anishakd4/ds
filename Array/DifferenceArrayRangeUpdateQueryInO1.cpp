#include<iostream>
#include<vector>

using namespace std;

vector<int> initializeArray(vector<int>& A){
    int n = A.size(); 

    vector<int> D(n + 1); 
  
    D[0] = A[0], D[n] = 0; 
    for (int i = 1; i < n; i++){
        D[i] = A[i] - A[i - 1]; 
    }
    return D; 
}

void printArray(vector<int> A, vector<int> D){
    for(int i=0; i<A.size(); i++){
        if(i == 0){
            A[i] = D[i];
        }else{
            A[i] = A[i-1] + D[i];
        }
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

void update(vector<int>& D, int l, int r, int k){
    D[l] = D[l] + k;
    D[r+1] = D[r+1] - k;
}

int main(){

    vector<int> A{ 10, 5, 20, 40 }; 

    vector<int> D = initializeArray(A);

    update(D, 0, 1, 10);
    printArray(A, D);

    update(D, 1, 3, 20);
    update(D, 2, 2, 30);
    printArray(A, D);

    return 0;
}