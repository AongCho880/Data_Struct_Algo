// ............. Binary Search Tree .............

#include<stdio.h>
#include<stdlib.h>

// Define Structure ...........
typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

// Create a new Node ..........
Node *create_node(int val){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert data in BST .............
void insert_in_bst(Node **root, int val){
    if((*root)==NULL){
        (*root) = create_node(val); 
    }
    else if((*root)->data > val){
        insert_in_bst(&((*root)->left), val);
    }
    else{
        insert_in_bst(&((*root)->right), val);
    }
}

// Pre-Order Traversal .................
void pre_order(Node *root){
    if(root != NULL){
        printf("%d ",root->data);
        pre_order(root->left);
        pre_order(root->right);
    }
}

// In_Order Traversal ..............
void in_order(Node *root){
    if(root!=NULL){
        in_order(root->left);
        printf("%d ",root->data);
        in_order(root->right);
    }
}

// Post_Order Traversal ...........
void post_order(Node *root){
    if(root!=NULL){
        post_order(root->left);
        post_order(root->right);
        printf("%d ",root->data);
    }
}

// Maing Function .................
int main(){
    FILE *fptr = fopen("test.txt","r");
    int size;
    fscanf(fptr,"%d",&size);

    Node *root = NULL;
    int data;
    for(int i=0;i<size;i++){
        fscanf(fptr,"%d",&data);
        insert_in_bst(&root,data);
    }
    fclose(fptr);

    printf("\nPre_Order Traversal: ");
    pre_order(root);

    printf("\nIn_order Traversal: ");
    in_order(root);

    printf("\nPost_order Traversal: ");
    post_order(root);

    return 0;
}