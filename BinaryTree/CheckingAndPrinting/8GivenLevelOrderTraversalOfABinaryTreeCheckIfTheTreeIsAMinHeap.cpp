#include<iostream>

using namespace std;

bool isMinHeap(int level[], int n){
    for(int i=0; i<n; i++){
        int child1 = 2*i +1;
        int child2 = 2*i +2;

        if(child1 < n && level[i] > level[child1]){
            return false;
        }

        if(child2 < n && level[i] > level[child2]){
            return false;
        }
    }

    return true;
}

int main(){
    int level[] = {10, 15, 14, 25, 30}; 
    int n = sizeof(level)/sizeof(level[0]); 

    if  (isMinHeap(level, n)) 
        cout << "True"; 
    else
        cout << "False"; 

    cout<<endl;
    
    return 0;
}