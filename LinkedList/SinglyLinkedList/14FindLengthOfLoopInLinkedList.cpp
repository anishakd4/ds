#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node* next;
};

struct Node* newNode(int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

int countNodes(struct Node* node){
    int count=1;
    struct Node* temp = node;
    temp = temp->next;
    while (temp != node){
        count++;
        temp = temp->next;
    }
    return count;
}

int countNodesInLoop(Node *head){
    struct Node* slow_ptr = head;
    struct Node* fast_ptr = head;

    while (slow_ptr && fast_ptr && fast_ptr->next){
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;

        if(slow_ptr == fast_ptr){
            return countNodes(slow_ptr);
        }
    }
    return 0;
}

int main(){

    struct Node* head = newNode(1);
    head->next = newNode(2);  
    head->next->next = newNode(3);  
    head->next->next->next = newNode(4);  
    head->next->next->next->next = newNode(5);

    head->next->next->next->next->next = head->next;

    cout<<countNodesInLoop(head)<<endl;

    return 0;
}