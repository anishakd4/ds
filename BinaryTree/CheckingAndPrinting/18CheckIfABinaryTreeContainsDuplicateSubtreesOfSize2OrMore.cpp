#include<iostream>
#include<unordered_set>

using namespace std;

char marker = '$';

struct Node{
    char data;
    Node *left, *right;
};

Node* newNode(int data){
    Node* new_node = new Node;
    new_node->left = new_node->right = NULL;
    new_node->data = data;
    return new_node;
}

string dupSubUtil(Node* root, unordered_set<string> &set){
    string s = "";
    if(root == NULL){
        return s + marker;
    }

    string lstr = dupSubUtil(root->left, set);
    if(lstr.compare("") == 0){
        return "";
    }
    string rstr = dupSubUtil(root->left, set);
    if(rstr.compare("") == 0){
        return "";
    }

    s = s + root->data + lstr + rstr;

    if (s.length() > 3 && set.find(s) != set.end()) {
        return "";
    }

    set.insert(s);

    return s;
}

int main(){

    Node *root = newNode('A'); 
    root->left = newNode('B'); 
    root->right = newNode('C'); 
    root->left->left = newNode('D'); 
    root->left->right = newNode('E'); 
    root->right->right = newNode('B'); 
    root->right->right->right = newNode('E'); 
    root->right->right->left= newNode('D'); 

    unordered_set<string> set;
    string str = dupSubUtil(root, set); 
  
    (str.compare("") == 0) ? cout << " Yes ": cout << " No " ;
    cout<<endl;

    return 0;
}