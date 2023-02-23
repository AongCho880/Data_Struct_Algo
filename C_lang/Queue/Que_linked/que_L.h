// ......... Implementation of Queue with Linked List ...............
// ......... Author: Aong Cho Thing Marma ...........................
// ................. Header File ....................................

#ifndef que_L
#define que_L

#include<stdio.h>
#include<stdlib.h>

// Define structure ............
typedef struct Node{
    int data;
    struct Node *next;
}Node;

// Create a new node ...................
Node *create_node(int data);

// Enqueue Function ...........................
void enque(Node **last, Node **start, int data, int *q_count, int mx_que_size);

// Dequeue Function ................
int deque(Node **start, int *q_count);

// Print Queue List ...................
void pirnt_que(Node *start, int q_count);

// Operations ..........................
void operations(Node *start, int q_count);

// Execute Operations .................................................................
int execute_operation(Node **start, Node **last, int *q_count, int operation,int mx_que_size);

#endif