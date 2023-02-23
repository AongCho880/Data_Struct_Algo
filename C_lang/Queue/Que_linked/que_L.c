// ......... Implementation of Queue with Linked List ...............
// ......... Author: Aong Cho Thing Marma ...........................
// ................. Function Definitions ....................................

#include<stdio.h>
#include"que_L.h"

// Create a new node ...................
Node *create_node(int data){
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Enqueue Function ...........................
void enque(Node **last, Node **start, int data, int *q_count, int mx_que_size){
    if(*q_count>=mx_que_size){
        printf("\nQueue List Overflow !!!\n");
        return;
    }
    Node *new_node = create_node(data);
    if(*last != NULL)
        (*last)->next = new_node;
    *last = new_node;

    if(*q_count==0)     // If Queue element is zero, start = last
        *start = *last;

    (*q_count)++;
}

// Dequeue Function ................
int deque(Node **start, int *q_count){
    if(*q_count == 0){
        printf("\nQueue Underflow !!! \n");
        return -1;
    }

    int data = (*start)->data;
    Node *temp = *start;
    *start = (*start)->next;
    (*q_count)--;
    free(temp);
    return data;
}

// Print Queue List ...................
void pirnt_que(Node *start, int q_count){
    printf("\nQueue List: ");
    while(start!=NULL){
        printf("%d ",start->data);
        start = start->next;
    }
    printf("\nQ_Count: %d\n",q_count);
}

// Operations ................
void operations(Node *start, int q_count){
    printf("\n....... Operations .......\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("0. Exit Program\n");
    pirnt_que(start,q_count);
}

// Execute Operations .................................................................
int execute_operation(Node **start, Node **last, int *q_count, int operation,int mx_que_size){
    if(operation==1){
        printf("Data to enqueue: ");
        int data; scanf("%d",&data);
        enque(last,start,data,q_count,mx_que_size);
    }
    else if(operation==2){
        return deque(start,q_count);
    }
    return 0;
}
