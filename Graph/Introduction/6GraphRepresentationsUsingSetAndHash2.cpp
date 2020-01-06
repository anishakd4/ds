#include<iostream>
#include<unordered_set>

using namespace std;

struct Graph{
    int v;
    unordered_set<int>* adj;
};

Graph* createGraph(int v){
    Graph* graph = new Graph;
    graph->v = v;
    graph->adj = new unordered_set<int>[v];
    return graph;
}

void addEdge(Graph* graph, int src, int dst){
    graph->adj[src].insert(dst);
    graph->adj[dst].insert(src);
}

void printGraph(Graph* graph){
    for(int i=0; i<graph->v; i++){
        unordered_set<int> st = graph->adj[i];

        unordered_set<int>::iterator itr;
        for(itr = st.begin(); itr!= st.end(); itr++){
            cout<<*itr<<" ";
        }
        cout<<endl;
    }
}

int main(){

    int V = 5; 
    struct Graph* graph = createGraph(V); 
    addEdge(graph, 0, 1); 
    addEdge(graph, 0, 4); 
    addEdge(graph, 1, 2); 
    addEdge(graph, 1, 3); 
    addEdge(graph, 1, 4); 
    addEdge(graph, 2, 3); 
    addEdge(graph, 3, 4); 
  
    printGraph(graph); 

    return 0;
}