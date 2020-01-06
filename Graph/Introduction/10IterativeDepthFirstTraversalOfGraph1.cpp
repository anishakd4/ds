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

        void addEdge(int u, int v){
            adj[u].push_back(v);
        }

        void dfs(int s){
            vector<bool> visited(v, false);

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

            cout<<endl;
        }
};

int main(){

    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 4);

    g.dfs(0);

    return 0;

}