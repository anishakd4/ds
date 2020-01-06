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
            adj[w].push_back(u);
        }

        void dfs(int s, vector<bool> &visited){
            visited[s] = true;

            for(int i=0; i<adj[s].size(); i++){
                if(!visited[adj[s][i]]){
                    dfs(adj[s][i], visited);
                }
            }
        }

        int countTrees(){
            vector<bool> visited(v, false);

            int ans = 0;
            for(int i=0; i<v; i++){
                if(visited[i] == false){
                    dfs(i, visited);
                    ans++;
                }
            }

            return ans;
        }
};

int main(){
    Graph g(5);
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(3, 4); 
    cout << g.countTrees()<<endl;;

    return 0;
}