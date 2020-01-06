#include<iostream>
#include<vector>

using namespace std;

int fillHeight(int parent[], int i, int visited[], int height[]){
    if(parent[i] == -1){
        visited[i] = 1;
        return 0;
    }

    if(visited[i] == 1){
        return height[i];
    }

    visited[i] = 0;
    height[i] = 1 + fillHeight(parent, parent[i], visited, height);

    return height[i];
}

int findHeight(int parent[], int n){
    int max_level = 0;

    int visited[n];
    int height[n];

    memset(visited, 0, sizeof(visited));
    memset(visited, 0, sizeof(height));

    for(int i=0; i<n ; i++){
        if(!visited[i]){
            height[i] = fillHeight(parent, i, visited, height);
        }
        max_level = max(max_level, height[i]);
    }

    return max_level;
}

int main(){

    int parent[] = { -1, 0, 0, 0, 3, 1, 1, 2 }; 
    int n = sizeof(parent)/sizeof(parent[0]);

    cout << "Height of N-ary Tree = " << findHeight(parent, n)<<endl;

    return 0;
}