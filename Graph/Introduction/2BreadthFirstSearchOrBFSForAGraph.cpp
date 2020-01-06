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

        void addEdge(int v, int w){
            adj[v].push_back(w);
        }

        void bfs(int s){
            bool visited[v];
            for(int i=0; i<v; i++){
                visited[i] = false;
            }

            queue<int> arr;
            visited[s] = true;
            arr.push(s);

            while(!arr.empty()){
                s = arr.front();
                cout<<s<<" ";
                arr.pop();

                for(int i=0; i<adj[s].size(); i++){
                    int m = adj[s][i];
                    if(!visited[m]){
                        arr.push(m);
                        visited[m] = true;
                    }
                }

            }

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
  
    cout << "Following is Breadth First Traversal " << "(starting from vertex 2) \n"; 
    g.bfs(2);

    return 0 ;
}