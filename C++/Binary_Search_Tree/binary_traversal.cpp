#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;

    // Constructor .............
    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Pre_Order Traversal ..........
void pre_order(Node *root){
    if(root==nullptr){
        return;
    }
    cout << root->data << " ";
    pre_order(root->left);
    pre_order(root->right);
}

// In_Order Traversal ..........
void in_order(Node *root){
    if(root==nullptr){
        return;
    }
    in_order(root->left);
    cout << root->data << " ";
    in_order(root->right);
}

// Post_Order ...........
void post_order(Node *root){
    if(root==nullptr){
        return;
    }
    post_order(root->left);
    post_order(root->right);
    cout << root->data << " ";
}


// Main Function ..........
int main(){
    // Level = 0
    Node *root = new Node(7);

    // Level = 1
    root->left = new Node(5);
    root->right = new Node(9);

    // Level = 2
    root->left->left = new Node(4);
    root->left->right = new Node(6);

    root->right->left = new Node(8);
    root->right->right = new Node(10);

    cout << "\nPre_order sequence: ";
    pre_order(root);
    
    cout << "\nIn_order sequence: ";
    in_order(root);

    cout << "\nPost_order sequence: ";
    post_order(root);

    return 0;
}

// ....... Tree ........

//          7       Level = 0
//        /  \
//       5    9     Level = 1
//      /\    /\
//     4  6  8  10  Level = 2
