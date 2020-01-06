#include<iostream>
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

        void printPath(vector<int> path){
            for(int i=0; i<path.size(); i++){
                cout<<path[i]<<" ";
            }
            cout<<endl;
        }

        bool isVisited(vector<int> path, int x){
            for(int i=0; i<path.size(); i++){
                if(path[i] == x){
                    return true;
                }
            }
            return false;
        }

        void findpaths(int src, int dst){
            queue<vector<int> > qu;

            vector<int> path;
            path.push_back(src);
            qu.push(path);

            while(!qu.empty()){
                path = qu.front();
                qu.pop();
                int last = path[path.size() - 1];

                if(last == dst){
                    printPath(path);
                }

                for(int i=0; i<adj[last].size(); i++){
                    if(!isVisited(path, adj[last][i])){
                        vector<int> newPath(path);
                        newPath.push_back(adj[last][i]);
                        qu.push(newPath);
                    }
                }
            }
        }
};

int main(){

    int v = 4;

    Graph g(v);

    g.addEdge(0, 3);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 0);
    g.addEdge(2, 1);
  
    int src = 2, dst = 3; 
    cout << "path from src " << src << " to dst " << dst << " are \n";  
    g.findpaths(src, dst); 

    return 0;
}