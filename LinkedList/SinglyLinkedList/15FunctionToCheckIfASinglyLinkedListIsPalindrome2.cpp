#include<iostream>

using namespace std;

struct Node{
    char data;
    struct Node* next;
};

void push(struct Node** head_ref, char new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void printList(struct Node* ptr){
    cout<<"Linked List: "<<endl;
    while (ptr != NULL){
        cout<<ptr->data<<endl;
        ptr = ptr->next;
    }
}

bool isPalindrome(Node* head){
    Node* slow_ptr = head;
    Node* fast_ptr = head;
    Node* prev_ptr = NULL;

    if(head != NULL && head->next != NULL){
        while (fast_ptr != NULL && fast_ptr->next != NULL){
            fast_ptr = fast_ptr->next->next;
            prev_ptr = slow_ptr;
            slow_ptr = slow_ptr->next;
        }
        
        if(fast_ptr == NULL){
            fast_ptr = slow_ptr;
            slow_ptr = prev_ptr; 
        }else{
            fast_ptr = slow_ptr->next;
            slow_ptr = prev_ptr; 
        }

        while (fast_ptr != NULL){
            if(fast_ptr->data != head->data){
                return false;
            }
            fast_ptr = fast_ptr->next;
            head = head->next;
        }
    }

    return true;
}

int main(){

    struct Node* head = NULL;
    char str[] = "abacaba";

    for(int i=0; str[i] != '\0'; i++){
        push(&head, str[i]);
        printList(head);
        isPalindrome(head) ? cout<<"is Palindrome"<<endl : cout<<"Not Palindrome"<<endl;
    }

    return 0;
}