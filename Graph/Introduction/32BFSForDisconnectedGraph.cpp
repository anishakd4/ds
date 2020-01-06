#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Graph{
    int v;
    vector<int> *adj;

    void printBoolVector(vector<bool> visited){
        for(int i=0; i<v; i++){
            cout<<visited[i]<<" ";
        }
        cout<<endl;
    }

    void BFSUtil(int i, vector<bool> &visited){
        queue<int> q;
        q.push(i);
        visited[i] = true;

        while(!q.empty()){
            i = q.front();
            q.pop();
            cout<<i<<" ";

            for(int j=0; j<adj[i].size(); j++){
                if(visited[adj[i][j]] == false){
                    q.push(adj[i][j]);
                    visited[adj[i][j]] = true;
                }
            }
        }
    }

    public:
        Graph(int v){
            this->v = v;
            adj = new vector<int>[v];
        }

        void addEdge(int u, int w){
            adj[u].push_back(w);
        }

        void BFS(){
            vector<bool> visited(v, false);
            for(int i=0; i<v; i++){
                if (visited[i] == false){
                    BFSUtil(i, visited); 
                }
            }
        }
};

int main(){

    Graph g(5);
  
    g.addEdge( 0, 4); 
    g.addEdge( 1, 2); 
    g.addEdge( 1, 3); 
    g.addEdge( 1, 4); 
    g.addEdge( 2, 3); 
    g.addEdge( 3, 4); 
    g.BFS(); 
    cout<<endl;

    return 0;
}