#include<iostream>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

void printRect(int *rect, int m, int n){
    int i, j; 
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            cout<<(*((rect+i*n) + j))<<" ";
        }
        cout<<endl;
    }
}

bool isPossible(int m, int n, int k, int r, vector<int> X, vector<int> Y){
    int rect[m][n];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            rect[i][j] = 0;
        }
    }
    //printRect((int *)rect, m, n);

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            for(int p=0; p<k; p++){
                if(sqrt(pow(X[p]-1-i, 2) + pow(Y[p]-1-j, 2)) <= r){
                    rect[i][j] = -1;
                }
            }
        }
    }
    //printRect((int *)rect, m, n);

    if(rect[0][0] == -1 && rect[m-1][n-1] == -1){
        return false;
    }

    queue<pair<int, int> > qu;
    rect[0][0] = 1;
    qu.push(make_pair(0, 0));

    while(!qu.empty()){
        pair<int, int> p = qu.front();
        qu.pop();
        int elex = p.first;
        int eley = p.second;

        if ((elex > 0) && (eley > 0) && (rect[elex - 1][eley - 1] == 0))  { 
            rect[elex - 1][eley - 1] = 1; 
            pair<int, int> v = make_pair(elex - 1, eley - 1); 
            qu.push(v); 
        } 
      
        if ((elex > 0) && (rect[elex - 1][eley] == 0)) { 
            rect[elex - 1][eley] = 1; 
            pair<int, int> v = make_pair(elex - 1, eley); 
            qu.push(v); 
        } 
        
        if ((elex > 0) && (eley < n - 1) &&  (rect[elex - 1][eley + 1] == 0)) { 
            rect[elex - 1][eley + 1] = 1; 
            pair<int, int> v = make_pair(elex - 1, eley + 1); 
            qu.push(v); 
        } 
      
        if ((eley > 0) && (rect[elex][eley - 1] == 0))  { 
            rect[elex][eley - 1] = 1; 
            pair<int, int> v = make_pair(elex, eley - 1); 
            qu.push(v); 
        } 
         
        if ((eley > n - 1) && (rect[elex][eley + 1] == 0)) { 
            rect[elex][eley + 1] = 1; 
            pair<int, int> v = make_pair(elex, eley + 1); 
            qu.push(v); 
        } 
      
        if ((elex < m - 1) && (eley > 0) && (rect[elex + 1][eley - 1] == 0)) { 
            rect[elex + 1][eley - 1] = 1; 
            pair<int, int> v = make_pair(elex + 1, eley - 1); 
            qu.push(v); 
        } 
        
        if ((elex < m - 1) && (rect[elex + 1][eley] == 0)) { 
            rect[elex + 1][eley] = 1; 
            pair<int, int> v = make_pair(elex + 1, eley); 
            qu.push(v); 
        } 
        
        if ((elex < m - 1) && (eley < n - 1) && (rect[elex + 1][eley + 1] == 0))  { 
            rect[elex + 1][eley + 1] = 1; 
            pair<int, int> v = make_pair(elex + 1, eley + 1); 
            qu.push(v); 
        } 

    }
    return (rect[m - 1][n - 1] == 1);   
}

int main(){

    // Test case 1 
    int m1 = 5, n1 = 5, k1 = 2, r1 = 1; 
    vector<int> X1;
    X1.push_back(1);
    X1.push_back(3); 
    vector<int> Y1;
    Y1.push_back(3);
    Y1.push_back(3); 
    if (isPossible(m1, n1, k1, r1, X1, Y1)) 
        cout << "Possible" << endl; 
    else
        cout << "Not Possible" << endl; 
    
    // Test case 2 
    int m2 = 5, n2 = 5, k2 = 2, r2 = 1; 
    vector<int> X2; 
    X2.push_back(1);
    X2.push_back(1); 
    vector<int> Y2; 
    Y2.push_back(2);
    Y2.push_back(3); 
    if (isPossible(m2, n2, k2, r2, X2, Y2)) 
        cout << "Possible" << endl; 
    else
        cout << "Not Possible" << endl; 

    return 0;
}