#include<iostream>
#include<unordered_set>

using namespace std;

struct Node{
    int data;
    struct Node* next;
};

struct Node* newNode(int new_data){
    Node *temp = new Node;
    temp->data = new_data;
    temp->next = NULL;
    return temp;
}

void printList(Node* node){
    cout<<"Linked list: "<<endl;
    while(node != NULL){
        cout<<node->data<<endl;
        node = node->next;
    }
}

void removeDuplicates(Node* head){
    unordered_set<int> seen;
    Node* current = head;
    Node* prev;

    while(current != NULL){
        if(seen.find(current->data) != seen.end()){
            prev->next = current->next;
            delete(current);
        }else{
            seen.insert(current->data);
            prev = current;
        }
        current = prev->next;
    }
}

int main(){

    struct Node* start = newNode(10);
    start->next = newNode(12);
    start->next->next = newNode(11);
    start->next->next->next = newNode(11);
    start->next->next->next->next = newNode(12);
    start->next->next->next->next->next = newNode(11);
    start->next->next->next->next->next->next = newNode(10);

    printList(start);

    removeDuplicates(start);

    printList(start);

}
