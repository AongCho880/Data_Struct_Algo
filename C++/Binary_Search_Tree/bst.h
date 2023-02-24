// ....... Binary Search Tree Implementation with C++ .........
// .................... Header File ...........................

#ifndef bst
#define bst

#include<iostream>
#include<stdlib.h>

struct Node{
    int data;
    Node *left;
    Node *right;

    // Constructor ........
    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Insert data in BST ........
Node *insert_in_bst(Node *root, int val){
    if(root==nullptr){
        return new Node(val);
    }
    else if(val < root->data){
        root->left = insert_in_bst(root->left,val);
    }
    else{
        root->right = insert_in_bst(root->right,val);
    }
    
    return root;
}

// Pre_Order Traversal ............
void pre_order(Node *root){
    if(root==nullptr){
        return;
    }
    std::cout << root->data << " ";
    pre_order(root->left);
    pre_order(root->right);
}

// In_Order Traversal ...........
void in_order(Node *root){
    if(root==nullptr){
        return;
    }
    in_order(root->left);
    std::cout << root->data << " ";
    in_order(root->right);
}

// Post_Order Traversal ...........
void post_order(Node *root){
    if(root==nullptr){
        return;
    }
    post_order(root->left);
    post_order(root->right);
    std::cout << root->data << " ";
}

#endif