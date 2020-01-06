#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Graph{
    int v;
    vector<int> *adj;

    public:
        Graph(int v){
            this->v = v;
            adj = new vector<int>[v];
        }

        void addEdge(int u, int w){
            adj[u].push_back(w);
        }

        void printLevels(int x){
            vector<bool> visited(v, false);
            vector<int> level(v, 0);
            queue<int> q;
            q.push(x);

            while(!q.empty()){
                x = q.front();
                q.pop();
                visited[x] = true;

                for(int i=0; i<adj[x].size(); i++){
                    if(!visited[adj[x][i]]){
                        q.push(adj[x][i]);
                        level[adj[x][i]] = level[x] + 1;
                    }
                }
            }
            for(int i=0; i<v; i++){
                cout<<i<<" - "<<level[i]<<endl;
            }
        }
};

int main(){

    int V = 8; 
    Graph graph(V);
  
    graph.addEdge(0, 1); 
    graph.addEdge(0, 2); 
    graph.addEdge(1, 3); 
    graph.addEdge(1, 4); 
    graph.addEdge(1, 5); 
    graph.addEdge(2, 5); 
    graph.addEdge(2, 6); 
    graph.addEdge(6, 7); 
  
    graph.printLevels(0); 
    return 0;
}