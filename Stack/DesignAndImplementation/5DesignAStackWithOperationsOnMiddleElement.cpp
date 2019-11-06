#include<iostream>

using namespace std;

class DllNode {
    public:
        int data;
        DllNode* prev;
        DllNode* next;
};

class MyStack{
    public:
        DllNode* head;
        DllNode* mid;
        int count;  
};

MyStack *createMyStack(){
    MyStack* ms = new MyStack();
    ms->count = 0;
    return ms;
}

void push(MyStack *ms, int new_data){
    DllNode* new_node = new DllNode();
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = ms->head;
    ms->count = ms->count + 1;

    if(ms->count == 1){
        ms->mid = new_node;
    }else{
        ms->head->prev = new_node;
        if(ms->count % 2 != 0){
            ms->mid = ms->mid->prev;
        }
    }
    ms->head = new_node;
}

int pop(MyStack* ms){
    if(ms->count == 0){
        cout<<"Stack is empty: "<<endl;
        return -1;
    }

    DllNode* head = ms->head;
    int item = head->data;
    ms->head = head->next;

    if(ms->head != NULL){
        ms->head->prev = NULL;
    }

    ms->count = ms->count - 1;

    if(ms->count % 2 == 0){
        ms->mid = ms->mid->next;
    }

    free(head);

    return item;
}

int findMiddle(MyStack* ms){
    if(ms->count == 0){
        cout << "Stack is empty now"<<endl;;  
        return -1;
    }

    return ms->mid->data;
}

int main(){

    MyStack* ms = createMyStack();

    push(ms, 11);
    push(ms, 22);  
    push(ms, 33);  
    push(ms, 44);  
    push(ms, 55);  
    push(ms, 66);  
    push(ms, 77); 

    cout << "Item popped is " << pop(ms) << endl;  
    cout << "Item popped is " << pop(ms) << endl;  
    cout << "Middle Element is " << findMiddle(ms) << endl;

    return 0;
}