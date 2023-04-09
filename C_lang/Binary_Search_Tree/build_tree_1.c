// Build tree using preOrder and inOrder sequence ...............

#include<stdio.h>
#include<stdlib.h>

// Read data from file ..........
void read_data(int **preOrder, int **inOrder, int *size){
    FILE *fptr = fopen("build_tree.txt","r");
    if(fptr == NULL){
        printf("\nFile doesn't extst !!!\n");
        return;
    }

    fscanf(fptr,"%d",size);

    *preOrder = (int *)calloc(*size,sizeof(int));
    *inOrder = (int *)calloc(*size,sizeof(int));

    for(int i=0;i<*size;i++){
        fscanf(fptr,"%d",&((*preOrder)[i]));
    }
    for(int i=0;i<*size;i++){
        fscanf(fptr,"%d",&((*inOrder)[i]));
    }

    fclose(fptr);
}

// Define Structure .............
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;

// Create a new node ............
Node* create_node(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Search Function ..............
int search(int *inOrder,int start, int end, int current) {
    for(int i=start;i<=end;i++) {
        if(inOrder[i] == current) {
            return i;
        }
    }
    return -1;
}

// Build Tree ...................
Node* build_tree(int *preOrder, int *inOrder,int start, int end) {
    if(start>end){
        return NULL;
    }
    static int indx = 0;
    int current = preOrder[indx];
    indx++;
    // Base Case
    int pos = search(inOrder,start, end, current);
    Node *node = create_node(current);
    if(start==end){
        return node;
    }
    node->left = build_tree(preOrder,inOrder,start,pos-1);
    node->right = build_tree(preOrder,inOrder,pos+1,end);

    return node;
}

// Pre_Order Traversal .........
void pre_order(Node *root){
    if(root!=NULL){
        printf("%d ",root->data);
        pre_order(root->left);
        pre_order(root->right);
    }
}

// In_Order Traversal ..........
void in_order(Node *root){
    if(root!=NULL){
        in_order(root->left);
        printf("%d ",root->data);
        in_order(root->right);
    }
}

void test(int *inOrder){
    for(int i=0;i<5;i++){
        printf("%d ",inOrder[i]);
    }
}

// Main Function ................
int main() {
    int size=0;
    int *preOrder, *inOrder;
    read_data(&preOrder,&inOrder,&size);

    Node *root = build_tree(preOrder,inOrder,0,size-1);

    printf("\nPre_order sequence: ");
    pre_order(root);
    printf("\nPost_order sequence: ");
    in_order(root);

    free(preOrder);
    free(inOrder);
    return 0;
}