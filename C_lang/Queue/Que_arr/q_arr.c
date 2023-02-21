// ......... Implementation of Queue with Array ............
// ............... Function Definitions ....................
// .......... Author: Aong Cho Marma .......................


#include<stdio.h>
#include "q_arr.h"

// Enqueue Function ......................................................
void enqueue(int *que, int mx_que_size, int *q_count, int *tail, int data){
    if((*q_count)>=mx_que_size){
        printf("\nError: Queue Overflow !!!\n");
        return;
    }
    (*tail)++;
    if((*tail) >= mx_que_size){         // Make array index circular
        (*tail) = (*tail)%mx_que_size;
    }
    que[(*tail)] = data;
    (*q_count)++;
}

// Dequeue Function ...........................................
int dequeue(int *que, int *head, int mx_que_size, int *q_count){
    if((*q_count)<=0){
        printf("\nError: Queue Underflow !!!\n");
        return -1;
    }
    (*head)++;
    if((*head) >= mx_que_size){
        (*head) = (*head)%mx_que_size;
    }
    (*q_count)--;
    return que[(*head)-1];
}

// Show Queue .................................................
void print_que(int *que, int mx_que_size, int head, int q_count){
    printf("\nQue List: ");
    for(int i=0;i<q_count;i++,(head)++){
        if(head>=mx_que_size)
            head = head % mx_que_size;
        printf("%d ",que[head]);
    }
    printf("\nQ_count: %d\n",q_count);
}

// Operations ........................
void operations(){
    printf("\n.......... Operations ...........\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("0. Exit Program\n");
}

// Execute operation ...................
int execute_operation(int *que, int mx_que_size, int *head, int *tail, int *q_count, int operation){
    if(operation==1){
        printf("Data to enque: ");
        int data; scanf("%d",&data);
        enqueue(que,mx_que_size,q_count,tail,data);
    }
    else if(operation==2){
        return dequeue(que,head,mx_que_size,q_count);
    }
    else{
        printf("\nInvalid Operation !\n");
    }
    return 0;
}