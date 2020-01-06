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
            adj[w].push_back(u);
        }

        int minEdges(int src, int dst){
            vector<bool> visited(v, false);
            vector<int> heights(v, 0);

            queue<int> qu;
            qu.push(src);

            while(!qu.empty()){
                int x = qu.front();
                qu.pop();
                visited[x] = true;

                for(int i=0; i<adj[x].size(); i++){
                    if(!visited[adj[x][i]]){
                        heights[adj[x][i]] = heights[x] + 1;
                        if(adj[x][i] == dst){
                            return heights[adj[x][i]];
                        }
                        qu.push(adj[x][i]);
                    }
                }
            }
            return -1;
        }

};

int main(){

    int n = 9; 
    Graph g(9); 
    g.addEdge( 0, 1); 
    g.addEdge( 0, 7); 
    g.addEdge( 1, 7); 
    g.addEdge( 1, 2); 
    g.addEdge( 2, 3); 
    g.addEdge( 2, 5); 
    g.addEdge( 2, 8); 
    g.addEdge( 3, 4); 
    g.addEdge( 3, 5); 
    g.addEdge( 4, 5); 
    g.addEdge( 5, 6); 
    g.addEdge( 6, 7); 
    g.addEdge( 7, 8); 
    int u = 0; 
    int v = 5; 
    cout << g.minEdges(u, v) << endl;

    return 0;
}