// ......... Implementation of Queue with Linked List ...............
// ......... Author: Aong Cho Thing Marma ...........................
// ............... Main Function ....................................

#include<stdio.h>
#include"que_L.h"

#define MAX_QUE_SIZE 10

int main(){
    Node *start=NULL, *last=NULL;
    int q_count=0;
    int operation;

    while(1){
        operations(start,q_count);
        printf("\nOperation: ");
        scanf("%d",&operation);
        if(operation==0){
            break;
        }
        execute_operation(&start,&last,&q_count,operation,MAX_QUE_SIZE);
    }

    printf("\nPrograme exited !\n");

    return 0;

}