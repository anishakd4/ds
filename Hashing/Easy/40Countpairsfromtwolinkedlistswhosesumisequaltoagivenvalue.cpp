#include<iostream>
#include<unordered_set>

using namespace std;

struct Node{
    int data;
    Node* next;
};

void push(struct Node** head_ref, int new_data){
    struct Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

int countPairs(Node* head1, Node* head2, int x){
    int count = 0;

    unordered_set<int> mySet;

    while(head1 != NULL){
        mySet.insert(head1->data);
        head1 = head1->next;
    }

    while(head2 != NULL){
        if(mySet.find(x - head2->data) != mySet.end()){
            count++;
        }
        head2 = head2->next;
    }

    return count;
}

int main(){

    struct Node* head1 = NULL; 
    struct Node* head2 = NULL; 
      
    // create linked list1 3->1->5->7 
    push(&head1, 7); 
    push(&head1, 5); 
    push(&head1, 1); 
    push(&head1, 3);     
      
    // create linked list2 8->2->5->3 
    push(&head2, 3); 
    push(&head2, 5); 
    push(&head2, 2); 
    push(&head2, 8); 
      
    int x = 10; 
      
    cout << "Count = "<< countPairs(head1, head2, x) << endl;

    return 0;
}