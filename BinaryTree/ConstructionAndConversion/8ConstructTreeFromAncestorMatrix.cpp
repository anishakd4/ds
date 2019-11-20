#include<iostream>
#include<map>

#define N 6

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

struct Node* newNode(int data){
    struct Node* new_node = new Node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void printMultimap(multimap<int, int> map){
    multimap<int, int> :: iterator itr;
    for(itr = map.begin(); itr != map.end(); itr++){
        cout<<itr->first<<" -- "<<itr->second<<endl;
    }
    cout << endl;
}

void printArray(int arr[]){
    for(int i=0; i<N; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

Node* ancestorTree(int mat[][N]){
    multimap<int, int> map;
    
    for(int i=0; i<N; i++){
        int sum = 0;
        for(int j=0; j<N; j++){
            sum = sum + mat[i][j];
        }
        map.insert(pair<int, int>(sum, i));
    }

    Node* root = NULL;
    Node* nodes[N];
    int parent[N] = {0};

    //printMultimap(map);

    multimap<int, int> :: iterator itr;
    for(itr = map.begin(); itr != map.end(); itr++){
        //cout<<itr->second<<endl;
        nodes[itr->second] = newNode(itr->second);
        root = nodes[itr->second];

        if(itr->first > 0){
            for (int i = 0; i < N; i++){
                if(mat[itr->second][i] == 1 && parent[i] == 0){
                    if(!nodes[itr->second]->left){
                        nodes[itr->second]->left = nodes[i];
                    }else{
                        nodes[itr->second]->right = nodes[i];
                    }
                    parent[i] = 1;
                }
            }
        }
        //printArray(parent);
    }

    return root;
}

void printInorder(Node* root){
    if(root == NULL){
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main(){

    int mat[N][N] = {
        { 0, 0, 0, 0, 0, 0 }, 
        { 1, 0, 0, 0, 1, 0 }, 
        { 0, 0, 0, 1, 0, 0 }, 
        { 0, 0, 0, 0, 0, 0 }, 
        { 0, 0, 0, 0, 0, 0 }, 
        { 1, 1, 1, 1, 1, 0 } 
    }; 
  
    Node* root = ancestorTree(mat); 
  
    cout << "Inorder traversal of tree is: "<<endl; 
    printInorder(root);
    cout<<endl; 
  
    return 0; 
}