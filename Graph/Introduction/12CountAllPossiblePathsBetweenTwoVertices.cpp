#include<iostream>
#include<vector>

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

        int countPaths(int s, int d){
            // bool *visited = new bool[v];
            // memset(visited, false, sizeof(bool));

            vector<bool> visited(v, false);

            int pathcount = 0;
            countPathsUtil(s, d, visited, pathcount);
            return pathcount;
        }

        void countPathsUtil(int s, int d, vector<bool> visited, int &pathcount){
            visited[s] = true;

            if(s == d){
                pathcount++;
            } else{
                for(int i=0; i<adj[s].size(); i++){
                    if(!visited[adj[s][i]]){
                        countPathsUtil(adj[s][i], d, visited, pathcount);
                    }
                }
            }
        }
};

int main(){

    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(0, 3); 
    g.addEdge(2, 0); 
    g.addEdge(2, 1); 
    g.addEdge(1, 3); 
  
    int s = 2, d = 3; 
    cout << g.countPaths(s, d)<<endl;

    return 0;
}