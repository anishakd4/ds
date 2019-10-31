#include<iostream>

using namespace std;

class StackNode {
    public:
        int data;
        StackNode* next;
};

StackNode* newNode(int data){
    StackNode* new_node = new StackNode();
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

int isEmpty(StackNode* root){
    return !root;
}

void push(StackNode** root, int data){
    StackNode* new_node = newNode(data);
    new_node->next = *root;
    *root = new_node;
    cout << data << " pushed to stack\n";
}

int pop(StackNode** root){
    if(isEmpty(*root)){
        return -1;
    }

    StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

int peek(StackNode* root){
    if(isEmpty(root)){
        return -1;
    }
    return root->data;
}

int main(){
    StackNode* root = NULL; 
  
    push(&root, 10); 
    push(&root, 20); 
    push(&root, 30); 
  
    cout << pop(&root) << " popped from stack\n"; 
  
    cout << "Top element is " << peek(root) << endl;
}