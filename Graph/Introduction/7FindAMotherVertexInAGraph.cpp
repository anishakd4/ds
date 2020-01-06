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

        void addEdge(int v, int w){
            adj[v].push_back(w);
        }

        void dfsUtil(int v, vector<bool> &visited){
            visited[v] = true;

            for(int i=0; i<adj[v].size(); i++){
                int m = adj[v][i];
                if(!visited[m]){
                    dfsUtil(m, visited);
                }
            }
        }

        int findMother(){
            vector<bool> visited(v, false);

            int ans = 0;

            for(int i=0; i<v; i++){
                if(visited[i] == false){
                    dfsUtil(i, visited);
                    ans = i;
                }
            }

            fill(visited.begin(), visited.end(), false);
            dfsUtil(ans, visited);

            for (int i=0; i<v; i++) {
                if (visited[i] == false) {
                    return -1;
                }
            }

            return ans;
        }
};

int main(){

    Graph g(7); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 3); 
    g.addEdge(4, 1); 
    g.addEdge(6, 4); 
    g.addEdge(5, 6); 
    g.addEdge(5, 2); 
    g.addEdge(6, 0); 
  
    cout << "A mother vertex is " << g.findMother() << endl; 
    return 0;
}