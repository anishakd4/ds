#include<iostream>
#include<stack>

using namespace std;

class Node{
    public:
        int data;
        Node (int d){
            data = d;
        }
        Node *next;
};

bool isPalindrome(Node* head){ 

    Node* temp = head;

    stack<int> s;

    while(temp != NULL){
        s.push(temp->data);
        temp = temp->next;
    }

    while (head != NULL){
        if(s.top() != head->data){
            return false;
        }
        s.pop();
        head = head->next;
    }
    return true;

}

int main(){

    Node one = Node(1);
    Node two = Node(2);
    Node three = Node(3);
    Node four = Node(2);
    Node five = Node(1);

    one.next = &two;
    two.next = &three;
    three.next = &four;
    four.next = &five;
    five.next = NULL;


    if(isPalindrome(&one)) {
        cout<<"Is Palindrome\n"; 
    }else{
        cout<<"Not Palindrome\n"; 
    }

    return 0;
}