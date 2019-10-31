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

int getCount(Node* node){
    int count = 0;
    while(node != NULL){
        node = node->next;
        count++;
    }
    return count;
}

int main(){
    Node* head = NULL;

    push(&head, 1);
    push(&head, 3);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);
    push(&head, 6);
    push(&head, 7);

    cout<<getCount(head)<<endl;

    return 0;

}