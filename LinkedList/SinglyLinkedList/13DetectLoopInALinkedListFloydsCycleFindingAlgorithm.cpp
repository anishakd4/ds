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
    *head_ref = new_node;
}

bool detectLoop(Node *head){
    Node* slow_ptr = head;
    Node* fast_ptr = head;

    while(slow_ptr && fast_ptr && fast_ptr->next){
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        if(slow_ptr == fast_ptr){
            return true;
        }
    }
    return false;
}

int main(){
    Node* head = NULL;

    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);

    head->next->next->next->next = head;

    if(detectLoop(head)){
        cout<<"Found Loop"<<endl;
    }else{
        cout<<"No Loop"<<endl;
    }

    return 0;
}