#include<iostream>
#include<unordered_set>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

void push(Node **head_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

bool detectLoop(struct Node* head){
    unordered_set<Node *> set;

    while(head != NULL){
        if(set.find(head) != set.end()){
            return true;
        }
        set.insert(head);
        head = head->next;
    }
    return false;
}

int main(){

    struct Node* head = NULL;

    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);

    head->next->next->next->next = head;

    if (detectLoop(head)) {
        cout << "Loop found"<<endl; 
    }else{
        cout << "No Loop"<<endl;;
    }

    return 0;
}