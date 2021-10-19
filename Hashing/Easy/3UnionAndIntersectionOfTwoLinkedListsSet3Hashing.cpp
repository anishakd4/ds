#include<iostream>
#include<unordered_map>

using namespace std;

struct Node{
    int data;
    Node* next;
};

void push(Node** head_ref, int data){
    struct Node* newNode = new Node;
    newNode->data = data;
    newNode->next = *head_ref;
    *head_ref = newNode;
}

void printList(Node* node){
    while(node != NULL){
        cout<<node->data<<" ";
        node = node->next;
    }
    cout<<endl;
}

Node* getUnion(unordered_map<int, int> comm){
    struct Node* result = NULL;

    unordered_map<int, int> :: iterator it;

    for(it=comm.begin(); it!=comm.end(); it++){
        push(&result, it->first);
    }

    return result;
}

Node* getIntersection(unordered_map<int, int> comm){
    struct Node* result = NULL;

    unordered_map<int, int> :: iterator it;

    for(it=comm.begin(); it!=comm.end(); it++){
        if(it->second == 2){
            push(&result, it->first);
        }
    }

    return result;
}

void storeElem(Node* head1, Node* head2,  unordered_map<int, int> &comm){
    while(head1 != NULL || head2 != NULL){
        if(head1 != NULL){
            comm[head1->data]++;
            head1 = head1->next;
        }

        if(head2 != NULL){
            comm[head2->data]++;
            head2 = head2->next;
        }
    }
}

void printUnionIntersection(Node* head1, Node* head2){
    unordered_map<int, int> comm;
    storeElem(head1, head2, comm);

    Node* intersection_list = getIntersection(comm); 
    Node* union_list = getUnion(comm); 
  
    printList(intersection_list); 
    printList(union_list);
}

int main(){

    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    push(&head1, 1); 
    push(&head1, 2); 
    push(&head1, 3); 
    push(&head1, 4); 
    push(&head1, 5); 
  
    push(&head2, 1); 
    push(&head2, 3); 
    push(&head2, 5); 
    push(&head2, 6); 

    printList(head1);
    printList(head2);

    printUnionIntersection(head1, head2);

    return 0;
}