#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Graph{
    int v;
    vector<int> *adj;

    void bfs(queue<int> &qu, bool visited[], int parent[]){
        int x = qu.front();
        qu.pop();
        
        for(int i=0; i<adj[x].size(); i++){
            if(!visited[adj[x][i]]){
                visited[adj[x][i]] = true;
                qu.push(adj[x][i]);
                parent[adj[x][i]] = x;
            }
        }
    }

    int isIntersecting(bool s_visited[], bool d_visited[]){
        for(int i=0; i<v; i++){
            if(s_visited[i] && d_visited[i]){
                return i;
            }
        }
        return -1;
    }

    void printPath(int s_parent[], int d_parent[], int src, int dst, int intersectNode){
        vector<int> path;
        int i = intersectNode;
        path.push_back(i);

        while(src != i){
            path.push_back(s_parent[i]);
            i = s_parent[i];
        }

        reverse(path.begin(), path.end());

        i = intersectNode;

        while(i != dst){
            path.push_back(d_parent[i]);
            i=d_parent[i];
        }

        cout<<"*****Path*****\n"; 
        for(int i=0; i<path.size(); i++){
            cout<<path[i]<<" ";
        }
        cout<<endl;
    }

    public:
        Graph(int v){
            this->v = v;
            adj = new vector<int>[v];
        }

        void addEdge(int u, int w){
            adj[u].push_back(w);
            adj[w].push_back(u);
        }

        int biDirSearch(int src, int dst){
            bool s_visited[v], d_visited[v];
            int s_parent[v], d_parent[v];
            queue<int> s_queue, d_queue;

            for(int i=0; i<v; i++){
                s_visited[i]=false;
                d_visited[i]=false;
            }

            s_queue.push(src);
            s_visited[src] = true;
            s_parent[src] = -1;

            d_queue.push(dst);
            d_visited[dst] = true;
            d_parent[dst] = -1;

            while(!s_queue.empty() && !d_queue.empty()){
                bfs(s_queue, s_visited, s_parent);
                bfs(d_queue, d_visited, d_parent);

                int intersectNode = isIntersecting(s_visited, d_visited);

                if(intersectNode != -1){
                    cout << "Path exist between " << src << " and " << dst << "\n"; 
                    cout << "Intersection at: " << intersectNode << "\n"; 
                    printPath(s_parent, d_parent, src, dst, intersectNode); 
                    return 1;
                }
            }

            return -1;
        }
};


int main(){

    int n=15; 
  
    int src=0; 
    int dst=14; 
  
    Graph g(n); 
    g.addEdge(0, 4); 
    g.addEdge(1, 4); 
    g.addEdge(2, 5); 
    g.addEdge(3, 5); 
    g.addEdge(4, 6); 
    g.addEdge(5, 6); 
    g.addEdge(6, 7); 
    g.addEdge(7, 8); 
    g.addEdge(8, 9); 
    g.addEdge(8, 10); 
    g.addEdge(9, 11); 
    g.addEdge(9, 12); 
    g.addEdge(10, 13); 
    g.addEdge(10, 14); 

    if (g.biDirSearch(src, dst) == -1) {
        cout << "Path don't exist between " << src << " and " << dst << "\n"; 
    }

    return 0;
}