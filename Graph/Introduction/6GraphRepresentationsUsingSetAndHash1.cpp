#include<iostream>
#include<set>

using namespace std;

struct Graph{
    int v;
    set<int, greater<int> >* adj;
};

Graph* createGraph(int v){
    Graph* graph = new Graph;
    graph->v = v;

    graph->adj = new set<int, greater<int> >[v];
    return graph;
}

void addEdge(Graph* graph, int src, int dest){
    graph->adj[src].insert(dest);
    graph->adj[dest].insert(src);
}

void printGraph(Graph* graph){
    for(int i=0; i<graph->v; i++){
        set<int, greater<int> > st = graph->adj[i];
        set<int, greater<int> >::iterator itr;

        for(itr = st.begin(); itr != st.end(); itr++){
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