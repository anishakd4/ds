#include<iostream>
#include<vector>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

Node* getNode(int data){
    Node* new_node = new Node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

bool find(Node* node, int k){
    if(node ==  NULL){
        return false;
    }

    if(node->data == k){
        return true;
    }

    return (find(node->left, k) || find(node->right, k));
}

Node* findLcaUtil(Node* root, int n1, int n2, bool &v1, bool &v2){
    if(root == NULL){
        return NULL;
    }

    if(root->data == n1){
        v1 = true;
        return root;
    }

    if(root->data == n2){
        v2 = true;
        return root;
    }

    Node* l = findLcaUtil(root->left, n1, n2, v1, v2);
    Node* r = findLcaUtil(root->right, n1, n2, v1, v2);

    if(l != NULL && r != NULL){
        return root;
    }

    if(l == NULL && r == NULL){
        return NULL;
    }

    return (l != NULL ? l : r);
}

Node* findLca(Node* root, int n1, int n2){
    bool v1 = false, v2 = false;

    Node* lca = findLcaUtil(root, n1, n2, v1, v2);

    if(v1 && v2){
        return lca;
    }

    if(v1){
        if(find(lca, n2)){
            return lca;
        }
    }
    if(v2){
        if(find(lca, n1)){
            return lca;
        }
    }

    return NULL;
}

bool printCommonPathUtil(Node* root, Node* lca){
    if(root == NULL){
        return false;
    }

    if(root == lca){
        cout<<root->data<<" ";
        return true;
    }

    if(printCommonPathUtil(root->left, lca) || printCommonPathUtil(root->right, lca)){
        cout<<root->data<<" ";
        return true;
    }

    return false;
}

void printCommonPath(Node* root, int n1, int n2){
    vector<int> arr;

    Node* lca = findLca(root, n1, n2);

    if(lca){
        printCommonPathUtil(root, lca);
        return;
    }

    cout << "No Common Path"<<endl; 
}

int main(){

    struct Node *root = getNode(1); 
    root->left = getNode(2); 
    root->right = getNode(3); 
    root->left->left = getNode(4); 
    root->left->right = getNode(5); 
    root->right->left = getNode(6); 
    root->right->right = getNode(7); 
    root->left->right->left = getNode(8); 
    root->right->left->right = getNode(9); 
          
    int n1 = 4, n2 = 8; 
    printCommonPath(root, n1, n2); 

    return 0;
}