// ......... Doubly Linked List Main Function ..........
// ......... Author: Aong Cho Marma ....................

#include<stdio.h>
#include"doubly_L.h"

int main(){
    Node *head=NULL, *tail=NULL;
    int count=0;

    create_list(&head,&tail,&count);

    int operation;
    while(1){
        operations();
        traverse(head,count);
        printf("\nOperation: ");
        scanf("%d",&operation);
        if(operation==0){
            break;
        }
        execute_operation(&head,&tail,&count,operation);
    }

    printf("\nProgram exited !\n");
    
    return 0;
}