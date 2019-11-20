#include<iostream>
#include<unordered_map>

using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void postorder(struct Node *root){
    struct Node *temp = root;
    unordered_map<Node*, Node*> parentMap;
    parentMap.insert(pair<Node *, Node*>(temp, NULL));

    while(temp){
        if(temp->left && parentMap.find(temp->left) == parentMap.end()){
            parentMap.insert(pair<Node*, Node*>(temp->left, temp));
            temp = temp->left;
        }else if(temp->right && parentMap.find(temp->right) == parentMap.end()){
            parentMap.insert(pair<Node*, Node*>(temp->right, temp));
            temp = temp->right;
        }else{
            cout<<temp->data<<" ";
            temp = (parentMap.find(temp))->second;
        }
    }

}

int main(){
    struct Node* root = newNode(8); 
    root->left = newNode(3); 
    root->right = newNode(10); 
    root->left->left = newNode(1); 
    root->left->right = newNode(6); 
    root->left->right->left = newNode(4); 
    root->left->right->right = newNode(7); 
    root->right->right = newNode(14); 
    root->right->right->left = newNode(13); 

    postorder(root); 
    cout<<endl;
    return 0;
}