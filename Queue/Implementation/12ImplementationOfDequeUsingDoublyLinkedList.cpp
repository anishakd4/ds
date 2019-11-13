#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *next, *prev;
};

struct Node* getNode(int data){
    Node* new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->prev = new_node->next = NULL;
    return new_node;
}

class Dequeue{
    Node *front;
    Node *rear;
    int size;

    public:
        Dequeue(){
            front = rear = NULL;
            size = 0;
        }

        int getsize(){
            return size;
        }

        bool isEmpty(){
            return (front == NULL);
        }

        int getFront(){
            if(isEmpty()){
                return -1;
            }
            return front->data;
        } 

        int getRear(){
            if(isEmpty()){
                return -1;
            }
            return rear->data;
        } 

        void erase(){
            rear = NULL;
            size = 0;

            while(front != NULL){
                Node *temp = front;
                front = front->next;
                free(temp);
            }
        }

        void insertFront(int data){
            Node *new_node = getNode(data);
            if(front ==  NULL){
                front = rear = new_node;    
            }else{
                new_node->next = front;
                front->prev = new_node;
                front = new_node;
            }
            size++;
        }

        void insertRear(int data){
            Node *new_node = getNode(data);
            if(front ==  NULL){
                front = rear = new_node;    
            }else{
                new_node->prev = rear;
                rear->next = new_node;
                rear = new_node;
            }
            size++;
        }
        void deleteFront(){
            if(isEmpty()){
                cout<<"Queue empty"<<endl;
            }else{
                Node *temp = front;

                front = front->next;

                if(front == NULL){
                    rear = NULL;
                }else{
                    front->prev = NULL;
                }

                free(temp);
                size--;
            }
        }

        void deleteRear(){
            if(isEmpty()){
                cout<<"Queue empty"<<endl;
            }else{
                Node *temp = rear;

                rear = rear->prev;

                if(rear == NULL){
                    front = NULL;
                }else{
                    rear->next = NULL;
                }

                free(temp);
                size--;
            }
        }
        
};

int main(){
    Dequeue dq; 
    
    dq.insertRear(5);  
    dq.insertRear(10); 
  
    cout << "Rear end element: " << dq.getRear() << endl; 
  
    dq.deleteRear();

    cout << "After deleting rear element new rear" << " is: " << dq.getRear() << endl; 
  
    dq.insertFront(15); 
  
    cout << "Front end element: " << dq.getFront() << endl; 
  
    cout << "Number of elements in Deque: " << dq.getsize() << endl; 
  
    dq.deleteFront(); 

    cout << "After deleting front element new " << "front is: " << dq.getFront() << endl; 
  
    return 0; 
}