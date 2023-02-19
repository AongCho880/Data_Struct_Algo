// Implementation of Stack with Linked List

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX_STACK_SIZE 10

// ........... Define a structure ................
typedef struct stack_node{
    int data;
    struct stack_node *next;
}stack_node;

// ........... Operations ................
void operations(){
    printf("\n........... Operations ...........\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("0. Exit\n");
}

// ........... Create a new Stack .................
stack_node *create_stack(int data){
    stack_node *node = (stack_node *)malloc(sizeof(stack_node));
    node->data = data;
    node->next = NULL;

    return node;
}

// ............... Traverse Stack ..................
void traverse_stack(stack_node *top, int stack_count){
    printf("\nStack List: ");
    while(top!=NULL){
        printf("%d ",top->data);
        top = top->next;
    }
    printf("\nStack_count: %d\n",stack_count);
}

// ............ Push .............
void push(stack_node **top, int *stack_count, int data){
    if((*stack_count)>=MAX_STACK_SIZE){
        printf("\n!!! Stack Overflow !!!\n");
        return;
    }
    stack_node *new_stack = create_stack(data);
    new_stack->next = *top;
    *top = new_stack;
    (*stack_count)++;
}

// ........... Pop ................
int pop(stack_node **top, int *stack_count){
    if((*stack_count)==0){
        printf("\n!!! Stack Underflow !!!\n");
        return INT_MIN;
    }
    stack_node *temp = *top;
    *top = (*top)->next;
    int data = temp->data;
    free(temp);
    (*stack_count)--;
    return data;
}

// ........... Main Function .............
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

    printf("\nProgram exited successfully\n");

    return 0;
}
