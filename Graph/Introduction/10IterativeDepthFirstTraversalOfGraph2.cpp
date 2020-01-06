#include<iostream>
#include<vector>
#include<stack>

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

        void dfsUtil(int s, vector<bool> &visited){
            stack<int> st;

            st.push(s);

            while(!st.empty()){
                s = st.top();
                st.pop();

                if(!visited[s]){
                    cout<<s<<" ";
                    visited[s] = true;
                }

                for(int i=0; i<adj[s].size(); i++){
                    if(!visited[adj[s][i]]){
                        st.push(adj[s][i]);
                    }
                }
            }
        }

        void dfs(){
            vector<bool> visited(v, false);
            
            for(int i=0; i<v; i++){
                if(!visited[i]){
                    dfsUtil(i, visited);
                }
            }
        }
};

int main(){

    Graph g(5);
    g.addEdge(1, 0); 
    g.addEdge(2, 1); 
    g.addEdge(3, 4); 
    g.addEdge(4, 0);

    g.dfs();

    return 0;
}