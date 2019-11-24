#include<iostream>
#define MAX 100
using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

struct Node* newNode(int data){
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void storePreOrder(Node* root, char arr[], int &i){
    if(root == NULL){
        return;
    }
    arr[i] = root->data;
    i++;
    storePreOrder(root->left, arr, i);
    storePreOrder(root->right, arr, i);
}

void storeInOrder(Node* root, char arr[], int &i){
    if(root == NULL){
        return;
    }
    storeInOrder(root->left, arr, i);
    arr[i] = root->data;
    i++;
    storeInOrder(root->right, arr, i);
}

bool isSubtree(Node* t, Node* s){
    if(s == NULL){
        return true;
    }
    if(t == NULL){
        return true;
    }

    int m=0, n=0;
    char inT[MAX], inS[MAX];

    storeInOrder(t, inT, m); 
    storeInOrder(s, inS, n); 

    if(strstr(inT, inS) == NULL){
        return false;
    }

    m=n=0;
    char preT[MAX], preS[MAX];
    storePreOrder(t, inT, m); 
    storePreOrder(s, inS, n); 

    return ((strstr(preT, preS) == NULL) ? false : true);
}

int main(){

    Node* T = newNode('a'); 
    T->left = newNode('b'); 
    T->right = newNode('d'); 
    T->left->left = newNode('c'); 
    T->right->right = newNode('e'); 
  
    Node* S = newNode('a'); 
    S->left = newNode('b'); 
    S->left->left = newNode('c'); 
    S->right = newNode('d'); 
  
    if (isSubtree(T, S)) 
        cout << "Yes: S is a subtree of T"; 
    else
        cout << "No: S is NOT a subtree of T";  

    cout<<endl;

    return 0;
}