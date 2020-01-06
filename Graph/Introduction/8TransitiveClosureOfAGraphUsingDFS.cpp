#include<iostream>
#include<vector>

using namespace std;

class Graph{
    int v;
    bool **tc;
    vector<int> *adj;

    void dfsUtil(int s, int v){
        tc[s][v] = true;

        for(int i=0; i<adj[v].size(); i++){
            int m = adj[v][i];
            if(tc[s][m] == false){
                dfsUtil(s, m);
            }
        }
    }

    public:
        Graph(int v){
            this->v = v;
            this->adj = new vector<int>[v];
            tc = new bool* [v];

            for(int i=0; i<v; i++){
                tc[i] = new bool[v];
                memset(tc[i], false, v*sizeof(bool));
            }
        }

        void addEdge(int u, int v){
            adj[u].push_back(v);
        }

        void transitiveClosure(){
            for(int i=0; i<v; i++){
                dfsUtil(i, i);
                for(int i=0; i<v; i++){
                    for(int j=0; j<v; j++){
                        cout<<tc[i][j]<<" ";
                    }
                    cout<<endl;
                }
                cout<<"______________"<<endl;
            }

            for(int i=0; i<v; i++){
                for(int j=0; j<v; j++){
                    cout<<tc[i][j]<<" ";
                }
                cout<<endl;
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
  
    cout << "Transitive closure matrix is \n"; 
    g.transitiveClosure(); 

    return 0;
}