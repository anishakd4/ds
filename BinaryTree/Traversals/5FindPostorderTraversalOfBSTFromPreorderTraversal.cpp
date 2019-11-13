#include<iostream>

using namespace std;

void findPostOrderUtil(int pre[], int n, int minVal, int maxVal, int &preIndex){
    if(preIndex == n){
        return;
    }

    if(pre[preIndex] < minVal || pre[preIndex] > maxVal){
        return;
    }

    int val = pre[preIndex];
    preIndex++;

    findPostOrderUtil(pre, n, minVal, val, preIndex); 
  
    findPostOrderUtil(pre, n, val, maxVal, preIndex);

    cout<<val<<" ";
}

void findPostOrder(int pre[], int n){
    int preIndex = 0;

    findPostOrderUtil(pre, n, INT_MIN, INT_MAX, preIndex);
}

int main(){

    int pre[] = {40, 30, 35, 80, 100};

    int n = sizeof(pre)/sizeof(pre[0]);

    findPostOrder(pre, n);
    cout<<endl;

    return 0;
}