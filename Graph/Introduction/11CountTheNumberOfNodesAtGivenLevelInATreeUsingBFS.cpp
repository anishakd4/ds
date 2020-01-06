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

        int bfs(int s, int l){
            bool visited[v] ;
            int level[v];

            for(int i=0; i<v; i++){
                visited[i] = false;
                level[i] = 0;
            }

            queue<int> q;
            q.push(s);
            visited[s] = true;

            while(!q.empty()){
                s = q.front();
                q.pop();

                for(int i=0; i<adj[s].size(); i++){
                    if(!visited[adj[s][i]]){
                        level[adj[s][i]] = level[s] + 1;
                        visited[adj[s][i]] = true;
                        q.push(adj[s][i]);
                    }
                }
            }

            int count = 0; 
            for (int i = 0; i < v; i++)  {
                if (level[i] == l) {
                    count++; 
                }
            }
        
            return count;   
        }
};

int main(){

    Graph g(6);
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 3); 
    g.addEdge(2, 4); 
    g.addEdge(2, 5); 
  
    int level = 2; 
  
    cout << g.bfs(0, level)<<endl;

    return 0;
}