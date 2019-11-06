#include<iostream>

using namespace std;

struct DqueueNode{
    int data;
    DqueueNode* next;
    DqueueNode* prev;
};

class Dequeue{
    DqueueNode* head;
    DqueueNode* tail;

    public:
        Dequeue(){
            head = tail = NULL;
        }

        bool isEmpty(){
            if(head ==  NULL){
                return true;
            }
            return false;
        }

        int size(){
            if(!isEmpty()){
                int len = 0;
                DqueueNode* temp = head;
                while(temp != NULL){
                    len++;
                    temp = temp->next;
                }
                return len;
            }
            return 0;
        }

        void insert_first(int x){
            DqueueNode* temp = new DqueueNode[sizeof(Dequeue)];
            temp->data = x;

            if(head == NULL){
                head = tail = temp;
                temp->next = temp->prev = NULL;
            }else{
                head->prev = temp;
                temp->next = head;
                temp->prev = NULL;
                head = temp;
            }
        }

        void insert_last(int x){
            DqueueNode* temp = new DqueueNode[sizeof(Dequeue)];
            temp->data = x;

            if(head == NULL){
                head = tail = temp;
                temp->next = temp->prev = NULL;
            }else{
                tail->next = temp;
                temp->next = NULL;
                temp->prev = tail;
                tail = temp;
            }   
        }

        void remove_first(){
            if(!isEmpty()){
                DqueueNode* temp = head;
                head = head->next;
                head->prev = NULL;
                free(temp);
                return;
            }
            cout<<"Empty list"<<endl;
        }

        void remove_last(){
            if(!isEmpty()){
                DqueueNode* temp = tail;
                tail = tail->prev;
                tail->next = NULL;
                free(temp);
                return;
            }
            cout<<"Empty list"<<endl;
        }

        void printList(){
            if(!isEmpty()){
                DqueueNode* temp = head;
                while (temp != NULL){
                    cout<<temp->data<<endl;
                    temp = temp->next;
                }
                return;
            }
            cout<<"Empty list"<<endl;
        }
};

class Stack: public Dequeue{
    public:
        void push(int x){
            insert_last(x);
        }

        void pop(){
            remove_last();
        }
};


class Queue: public Dequeue{
    public:
        void enqueue(int x){
            insert_last(x);
        }

        void dequeue(){
            remove_first();
        }
};


int main(){

    Stack stk; 
  
    stk.push(7); 
    stk.push(8); 
    cout << "Stack: "<<endl; 
    stk.printList(); 
  
    stk.pop(); 
    cout << "Stack: "<<endl; 
    stk.printList(); 
  
    
    Queue que; 
  
    que.enqueue(12); 
    que.enqueue(13); 
    cout << "Queue: "<<endl; 
    que.printList(); 
  
    que.dequeue(); 
    cout << "Queue: "<<endl; 
    que.printList(); 
  
    cout << "Size of Stack is " << stk.size() << endl; 
    cout << "Size of Queue is " << que.size() << endl; 

    return 0;
}