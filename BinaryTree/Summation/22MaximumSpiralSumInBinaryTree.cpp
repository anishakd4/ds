#include<iostream>
#include<stack>
#include<vector>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

Node* newNode(int data){
    Node* new_node = new Node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

int maxSubArraySum(vector<int> arr){
    int max_so_far = arr[0];
    int curr_sum = arr[0];

    for(int i=1; i<arr.size(); i++){
        curr_sum = max(arr[i], curr_sum + arr[i]);
        max_so_far = max(max_so_far, curr_sum);
    }

    return max_so_far;
}

void printVector(vector<int> vec){
    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

int maxSpiralSum(Node* root){

    if(root == NULL){
        return 0;
    }

    vector<int> arr;

    stack<Node*> st1;
    stack<Node*> st2;

    st1.push(root);

    while(!st1.empty() || !st2.empty()){

        while(!st1.empty()){
            Node *temp = st1.top();
            st1.pop();

            arr.push_back(temp->data);

            if(temp->left){
                st2.push(temp->left);
            }
            if(temp->right){
                st2.push(temp->right);
            }
        }

        while(!st2.empty()){
            Node *temp = st2.top();
            st2.pop();

            arr.push_back(temp->data);

            if(temp->right){
                st1.push(temp->right);
            } 
            if(temp->left){
                st1.push(temp->left);
            }
        }
    }

    printVector(arr);

    return maxSubArraySum(arr);
}

int main(){

    Node* root = newNode(-2); 
    root->left = newNode(-3); 
    root->right = newNode(4); 
    root->left->left = newNode(5); 
    root->left->right = newNode(1); 
    root->right->left = newNode(-2); 
    root->right->right = newNode(-1); 
    root->left->left->left = newNode(-3); 
    root->right->right->right = newNode(2); 
  
    cout << "Maximum Spiral Sum = " << maxSpiralSum(root) << endl;
    return 0;
}