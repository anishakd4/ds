#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

class Graph{
    int v;
    vector<int> *adj;

    void printVector(vector<int> vec){
        for(int i=0;i<vec.size(); i++){
            cout<<vec[i]<<" ";
        }
        cout<<endl;
    }

    void printAdj(){
        for(int i=0;i<v; i++){
            cout<<adj[i].size()<<" ";
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

        int bfs(int x, int y){
            vector<int> visited(v, 0);
            visited[x] = 1;
            queue<int> q;
            q.push(x);
            //printAdj();
            while(!q.empty()){
                x = q.front();
                q.pop();
                //cout<<adj[x].size()<<" ";
                for(int i=0; i<adj[x].size(); i++){
                    if(visited[adj[x][i]] == 0){
                        visited[adj[x][i]] = visited[x] + 1;
                        q.push(adj[x][i]);
                    }
                    if(adj[x][i] == y){
                        return visited[adj[x][i]] - 1;
                    }
                }
            }
            //printVector(visited);
            return -1;
        }

};

void SieveOfEratosThenes(vector<int> &vec){
    int n = 9999;
    vector<bool> primes(n+1, true);

    for(int p=2; p*p <= n; p++){
        if(primes[p] == true){
            for(int i=p*p; i<=n; i= i+p){
                primes[i]=false;
            }
        }
    }
    for(int i=1000; i<=n ;i++){
        if(primes[i] == true){
            vec.push_back(i);
        }
    }
}

void printVector(vector<int> vec){
    for(int i=0;i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

bool compare(int x, int y){
    string s1 = to_string(x); 
    string s2 = to_string(y); 
    int c = 0; 
    if (s1[0] != s2[0]) 
        c++; 
    if (s1[1] != s2[1]) 
        c++; 
    if (s1[2] != s2[2]) 
        c++; 
    if (s1[3] != s2[3]) 
        c++; 
  
    return (c == 1); 
}

int shortestPath(int num1, int num2){
    vector<int> primes;
    SieveOfEratosThenes(primes);
    //printVector(primes);

    Graph g(primes.size());
    for(int i=0; i<primes.size(); i++){
        for(int j=i+1; j<primes.size(); j++){
            if(compare(primes[i], primes[j])){
                //cout<<primes[i]<<"-"<<primes[j]<<" ";
                g.addEdge(i, j);
            }
        }
    }

    int x;
    int y;
    int c=0;
    for (int j = 0; j < primes.size(); j++)  {
        if (primes[j] == num1) {
            x = j;
            c++;
        }
        if (primes[j] == num2) {
            y = j;
            c++;
        }
        if(c == 2){
            break;
        }
    } 
    //cout<<x<<" "<<y<<endl;

    return g.bfs(x, y);
}

int main(){

    int num1 = 1373, num2 = 8017; 
    cout << shortestPath(num1, num2)<<endl; 

    return 0;
}