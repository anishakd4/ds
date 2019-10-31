#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

void push(Node** head_ref, int new_data){
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;
    (*head_ref) = new_node;
}

bool search(Node* head, int key){
    Node* current = head;

    while(current != NULL){
        if(current->data == key){
            return true;
        }
        current = current->next;
    }

    return false;
}

int main(){
    Node* head = NULL;

    push(&head, 10);
    push(&head, 30);
    push(&head, 11);
    push(&head, 21);
    push(&head, 14);

    search(head, 21) ? cout<<"YES"<<endl : cout<<"NO"<<endl;

    return 0;
}