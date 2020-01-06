#include<iostream>
#include<map>
#include<vector>
#include<cmath>

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

void printVector(vector<int> arr){
    cout<<endl;
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void printMap(map<int, int> mapi){
    cout<<endl;
    map<int, int> :: iterator it;
    for(it = mapi.begin(); it != mapi.end(); it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    cout<<endl;
}

void printSegmentTree(int *st, int n){
    cout<<"segment tree"<<endl;
    for(int i=0; i<n; i++){
        cout<<st[i]<<" ";
    }
    cout<<endl;
}

int RMQUtil(int *st, int ss, int se, int qs, int qe, int si, vector<int> level){
    if(qs <= ss && qe >= se){
        return st[si];
    }else if (se < qs || ss > qe) {
        return -1;
    }

    int mid = (ss + se)/2; 
  
    int q1 = RMQUtil(st, ss, mid, qs, qe, 2*si + 1, level); 
    int q2 = RMQUtil(st, mid+1, se, qs, qe, 2*si + 2, level); 
  
    if (q1==-1){
        return q2; 
    }else if (q2==-1) {
        return q1;
    } 
  
    return (level[q1] < level[q2]) ? q1 : q2;
}

int RMQ(int *st, int n, int qs, int qe, vector<int> level){
    if(qs < 0 || qe > n-1 || qs > qe){
        return -1;
    }

    return RMQUtil(st, 0, n-1, qs, qe, 0,level);
}

void constructStUtil(vector<int> level, int* st, int ss, int se, int si){
    if(ss == se){
        st[si] = ss;
        return;
    }

    int mid = (ss + se)/2;
    constructStUtil(level, st, ss, mid, 2*si + 1);
    constructStUtil(level, st, mid+1, se, 2*si + 2);

    if(level[st[2*si + 1]] < level[st[2*si + 2]]){
        st[si] = st[2*si + 1];
    }else{
        st[si] = st[2*si + 2];
    }
}

int* constructSt(vector<int> level){

    int x = level.size();
    x = ceil(log2(x));
    int max_size = 2*pow(2, x) - 1;

    int *st = new int[max_size];
    constructStUtil(level, st, 0, level.size()-1, 0);

    printSegmentTree(st, max_size);

    return st;
}

void eulerTour(Node* root, int l, vector<int> &euler, vector<int> &level, map<int , int> &firstOccurrence){
    if(root == NULL){
        return;
    }

    euler.push_back(root->data);
    level.push_back(l);

    if(firstOccurrence.find(root->data) == firstOccurrence.end()){
        firstOccurrence[root->data] = euler.size() - 1;
    }

    if(root->left){
        eulerTour(root->left, l+1, euler, level, firstOccurrence);
        euler.push_back(root->data);
        level.push_back(l);
    }

    if(root->right){
        eulerTour(root->right, l+1, euler, level, firstOccurrence);
        euler.push_back(root->data);
        level.push_back(l);
    }

}

int findLCA(Node* root, int n1, int n2){
    map<int , int> firstOccurrence;
    vector<int> euler;
    vector<int> level;

    eulerTour(root, 0, euler, level, firstOccurrence);

    printVector(euler);
    printVector(level);
    printMap(firstOccurrence);

    int *st = constructSt(level);

    int index;
    if (firstOccurrence[n1] < firstOccurrence[n2]) {
        index = RMQ(st, level.size(), firstOccurrence[n1], firstOccurrence[n2], level); 
    }else{
        index = RMQ(st, level.size(), firstOccurrence[n2], firstOccurrence[n1], level);
    } 
    

    return euler[index];
}

int main(){

    Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->left->right->left = newNode(8); 
    root->left->right->right = newNode(9); 
  
    int u = 4, v = 9; 
    printf("The LCA of node %d and node %d is node %d.\n", u, v, findLCA(root, u, v)); 

    return 0;
}