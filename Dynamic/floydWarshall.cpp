#include<iostream>

#define v 4

#define INF 99999

using namespace std;

void printSolution(int arr[v][v]){
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            if(arr[i][j] == INF){
                printf("%7s", "INF");
            }else{
                printf("%7d", arr[i][j]);
            }
        }
        cout<<endl;
    }
}

void floydWarshall(int graph[v][v]){

    int dist[v][v];

    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            dist[i][j] = graph[i][j];
        }
    }

    for(int k=0; k<v; k++){
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printSolution(dist);
}

int main(){
    int graph[v][v] = { {0,   5,  INF, 10}, 
                        {INF, 0,   3, INF}, 
                        {INF, INF, 0,   1}, 
                        {INF, INF, INF, 0} 
                      }; 

    floydWarshall(graph);

    return 0;
}