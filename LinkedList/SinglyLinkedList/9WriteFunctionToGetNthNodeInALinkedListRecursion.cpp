#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

void push(Node **head_ref, int new_data){
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

int GetNth(Node* head, int count, int index){
    int count = 1;

    if(count == n){
        return head->data;
    }

    return GetNth(head->next, n-1);
}

int main(){
    Node* head = NULL;

    push(&head, 1);
    push(&head, 4);
    push(&head, 1);
    push(&head, 12);
    push(&head, 1);

    cout<<"Element at index 3 is " <<GetNth(head, 0, 3)<<endl;  

    return 0;
}