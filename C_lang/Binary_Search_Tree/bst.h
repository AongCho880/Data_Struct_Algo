// ........... Binary Search Tree Implementation ............
// ........... Author: Aong Cho Marma .......................
// .................. Header File ...........................

#ifndef bst
#define bst

#include<stdio.h>
#include<stdlib.h>

// Define structure .............
typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

// Create a new node ............
Node *create_node(int val){
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// Insert node in Binary Search Tree (Implemented with double pointer)..........
void insert_in_bst(Node **root,int val){
    if((*root)==NULL){
        (*root) = create_node(val);
    }
    else if((*root)->data > val){
        insert_in_bst(&((*root)->left),val);
    }
    else{
        insert_in_bst(&((*root)->right),val);
    }
}

// Pre_Order Traversal ................
void pre_order(Node *root){
    if(root == NULL){
        return;
    }
    printf("%d ",root->data);
    pre_order(root->left);
    pre_order(root->right);
}

// In_Order Traversal .............
void in_order(Node *root){
    if(root==NULL){
        return;
    }
    in_order(root->left);
    printf("%d ",root->data);
    in_order(root->right);
}

// Post_Order Traversal .........
void post_order(Node *root){
    if(root==NULL){
        return;
    }
    post_order(root->left);
    post_order(root->right);
    printf("%d ",root->data);
}

#endif