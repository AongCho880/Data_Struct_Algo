#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

// Construct a new node ...................
Node *create_node(int val){
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// Pre_order Traverse ........
void pre_order(Node *root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->data);
    pre_order(root->left);
    pre_order(root->right);
}

// In_Order Traversal .......
void in_order(Node *root){
    if(root==NULL){
        return;
    }
    in_order(root->left);
    printf("%d ",root->data);
    in_order(root->right);
}

// Post_Order Traversal ......
void post_order (Node *root){
    if(root==NULL){
        return;
    }
    post_order(root->left);
    post_order(root->right);
    printf("%d ",root->data);
}

// Main Function ................
int main(){
    Node *root = NULL;

    // Level = 0
    root = create_node(7);

    // Level = 1
    root->left = create_node(5);
    root->right = create_node(9);

    // Level = 2
    root->left->left = create_node(4);
    root->left->right = create_node(6);

    root->right->left = create_node(8);
    root->right->right = create_node(10);

    printf("\nPre_order sequence: ");
    pre_order(root);

    printf("\nIn_order sequence: ");
    in_order(root);

    printf("\nPost_order sequence: ");
    post_order(root);

    return 0;
}


// ....... Tree .......

//          7       Level = 0
//        /  \
//       5    9     Level = 1
//      /\    /\
//     4  6  8  10  Level = 2
