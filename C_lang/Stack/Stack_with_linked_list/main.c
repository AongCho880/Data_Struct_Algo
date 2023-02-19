// Main function for stack with linked list.
// Author: Aong Cho Marma

#include<stdio.h>
#include"stack_L.h"

int main(){
    stack_node *top = NULL;
    int stack_count = 0;

    int operation;

    while(1){
        operations();
        traverse_stack(top,stack_count);
        printf("\n> Operation: "); scanf("%d",&operation);
        if(operation==0){
            break;
        }
        else if(operation==1){
            int data;
            printf("Data to push: "); scanf("%d",&data);
            push(&top,&stack_count,data);
        }
        else if(operation==2){
            int data = pop(&top,&stack_count);
        }
        else{
            printf("\nInvalid Operation !!!\n");
        }
    }

    printf("\nProgram exited successfully.\n");

    return 0;
}