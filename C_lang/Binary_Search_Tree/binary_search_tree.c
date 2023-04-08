// ........ Binary Search Tree ............
// ........... Main Function ..............

#include<stdio.h>
#include "bst.h"

int main(){

    FILE *fptr = fopen("data.txt","r");
    if(fptr==NULL){
        printf("\nFile doesn't exist !!!\n");
    }

    int n;
    fscanf(fptr,"%d",&n);
    Node *root = NULL;

    // Data insertion ..............
    for(int i=0;i<n;i++){
        int data; fscanf(fptr,"%d",&data);
        insert_in_bst(&root,data);
    }

    // Pre_Order Sequence ...........
    printf("\nPre_order sequence: ");
    pre_order(root);

    // In_Order Sequence ............
    printf("\nIn_order sequence: ");
    in_order(root);

    // Post_Order Sequence ...........
    printf("\nPost_order sequence: ");
    post_order(root);

    return 0;
}