#include<iostream> 
using namespace std; 

struct Job 
{ 
	char id; 
	int deadLine, profit; 
}; 

struct DisjointSet 
{ 
	int *parent; 

	DisjointSet(int n) 
	{ 
		parent = new int[n+1]; 

		for (int i = 0; i <= n; i++) {
            parent[i] = i; 
        }
	} 

	int find(int s) 
	{ 
		if (s == parent[s]) {
            return s;
        } 
		return parent[s] = find(parent[s]); 
	} 

	void merge(int u, int v) 
	{
		parent[v] = u; 
	} 

    void printSet(int n){
        for(int i=0; i<n; i++){
            cout<<parent[i]<<" ";
        }
        cout<<endl;
    }
}; 

bool cmp(Job a, Job b) 
{ 
	return (a.profit > b.profit); 
} 

int findMaxDeadline(struct Job arr[], int n) 
{ 
	int ans = INT_MIN; 
	for (int i = 0; i < n; i++) {
        ans = max(ans, arr[i].deadLine); 
    }
	return ans; 
} 

void printJobScheduling(Job arr[], int n) 
{ 
	sort(arr, arr + n, cmp); 

	int maxDeadline = findMaxDeadline(arr, n); 
    cout<<"maxDeadline: "<<maxDeadline<<endl;
	DisjointSet ds(maxDeadline); 

	for (int i = 0; i < n; i++) 
	{ 
		int availableSlot = ds.find(arr[i].deadLine); 
        cout<<"availableSlot: "<<maxDeadline<<endl;

		if (availableSlot > 0) 
		{
			ds.merge(ds.find(availableSlot - 1), availableSlot); 
			cout <<"job added : "<< arr[i].id << " " << endl; 
		} 
	} 
    cout<<endl;
} 


int main() 
{ 
	Job arr[] = { { 'a', 2, 100 }, { 'b', 1, 19 }, 
				{ 'c', 2, 27 }, { 'd', 1, 25 }, 
				{ 'e', 3, 15 } }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << "Following jobs need to be "<< "executed for maximum profit\n"; 
	printJobScheduling(arr, n); 
	return 0; 
} 
