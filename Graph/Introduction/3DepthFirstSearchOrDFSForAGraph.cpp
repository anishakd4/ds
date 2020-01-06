#include<iostream>
#include<vector>

using namespace std;

class Graph{
    int v;
    vector<int> *adj;
    void dfsUtil(int v, bool visited[]){
        visited[v] = true;
        cout<<v<<" ";

        for(int i=0; i<adj[v].size(); i++){
            int m = adj[v][i];
            if(!visited[m]){
                dfsUtil(m, visited);
            }
        }
    }

    public:
        Graph(int v){
            this->v = v;
            adj = new vector<int>[v];
        }

        void addEdge(int v, int w){
            adj[v].push_back(w);            
        }

        void dfs(int v){
            bool visited[v];
            for(int i=0; i<v; i++){
                visited[v] = false;
            }
            dfsUtil(v, visited);
        }
};

int main(){

    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    cout << "Following is Depth First Traversal (starting from vertex 2) \n"; 
    g.dfs(2);
    cout<<endl;

    return 0;
}