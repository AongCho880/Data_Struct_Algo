// Header file for stack with linked list.
// Author: Aong Cho Marma

#ifndef stack_L
#define stack_L

// ........... Define a structure ........
typedef struct stack_node{
    int data;
    struct stack_node *next;
}stack_node;

// ........... Operations ................
void operations();

// ........... Create a new Stack ........
stack_node *create_stack(int data);

// ........... Traverse Stack ............
void traverse_stack(stack_node *top, int stack_count);

// ........... Push .....................
void push(stack_node **top, int *stack_count, int data);

// ........... Pop .....................
int pop(stack_node **top, int *stack_count);

#endif