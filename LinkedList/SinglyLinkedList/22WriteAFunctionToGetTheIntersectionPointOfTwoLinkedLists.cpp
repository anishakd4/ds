#include<iostream>
#include<unordered_set>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

int getIntesectionNode(Node* head1, Node* head2){
    unordered_set<Node *> set;
    while (head1 != NULL){
        set.insert(head1);
        head1 = head1->next;
    }

    while (head2 != NULL){
        if(set.find(head2) != set.end()){
            return head2->data;
        }
        head2=head2->next;
    }
    return -1;
}

int main(){

    Node* newNode; 
  
    Node* head1 = new Node(); 
    head1->data = 10; 
  
    Node* head2 = new Node(); 
    head2->data = 3; 
  
    newNode = new Node(); 
    newNode->data = 6; 
    head2->next = newNode; 
  
    newNode = new Node(); 
    newNode->data = 9; 
    head2->next->next = newNode; 
  
    newNode = new Node(); 
    newNode->data = 15; 
    head1->next = newNode; 
    head2->next->next->next = newNode; 
  
    newNode = new Node(); 
    newNode->data = 30; 
    head1->next->next = newNode; 
  
    head1->next->next->next = NULL; 

    cout << "The node of intersection is " << getIntesectionNode(head1, head2)<<endl;; 

    return 0;
}