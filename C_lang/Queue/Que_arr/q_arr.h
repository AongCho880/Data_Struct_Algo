// ......... Implementation of Queue with Array ............
// .................. Header File ..........................
// .......... Author: Aong Cho Marma .......................

#ifndef q_arr
#define q_arr

#include<stdio.h>

// Operations ........................
void operations();

// Execute operation ...................
int execute_operation(int *que, int mx_que_size, int *head, int *tail, int *q_count, int operation);


// Enqueue Function ......................................................
void enqueue(int *que, int mx_que_size, int *q_count, int *tail, int data);

// Dequeue Function ............................................
int dequeue(int *que, int *head, int mx_que_size, int *q_count);

// Show Queue .................................................
void print_que(int *que, int mx_que_size, int head, int q_count);


#endif