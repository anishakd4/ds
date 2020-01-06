#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Graph{
    int root_index;
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

        void setRootIndex(int root_index){
            this->root_index = root_index;
        }

        int findHeight(){
            int max_level = 0;
            queue<pair<int, int> > qu;
            vector<bool> visited(v, false);
            qu.push(make_pair(root_index, 0));

            while(!qu.empty()){
                pair<int, int> p = qu.front();
                qu.pop();
                max_level = max(max_level, p.second);
                visited[p.first] = true;

                for(int i=0; i<adj[p.first].size(); i++){
                    if(visited[adj[p.first][i]] == false){
                        qu.push(make_pair(adj[p.first][i], p.second + 1));
                    }
                }
            }

            return max_level;
        }
};

Graph build_tree(int parent[], int n){

    Graph g(n);
    int root_index = 0;
    g.setRootIndex(root_index);

    for(int i=0; i<n; i++){
        if(parent[i] == -1){
            g.setRootIndex(i);
        }else{
            g.addEdge(i, parent[i]);
        }
    }

    return g;
}

int main(){

    int parent[] = { -1, 0, 1, 2, 3 }; 

    int n = sizeof(parent)/sizeof(parent[0]);
    Graph g = build_tree(parent, n);
    
    int h = g.findHeight(); 
    cout << "Height of N-ary Tree=" << h <<endl;

    return 0;
}