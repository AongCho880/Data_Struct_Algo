// Stack implementation with array. Here overflow and underflow is maintained by stack_count;
// Author: Aong Cho Marma

#include<stdio.h>

#define MAX_STACK_SIZE 10

// ....... Operations ..........
void operations(){
    printf("\n....... Operations ........\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("0. Exit\n");
}

// ....... Print Stack ..........
void print_stack(int *stack, int stack_count){
    printf("\nStack: ");
    for(int i=stack_count-1;i>=0;i--)
        printf("%d ",stack[i]);
    printf("\nStack_count: %d\n",stack_count);
}


//........ Push Function .............
void push(int *stack, int data, int *stack_count, int *top_indx){
    if(*stack_count>=MAX_STACK_SIZE){   // Check if the Stack is full or not;
        printf("\n!!! Stack Overflow !!!\n");
        return;
    }
    stack[++(*top_indx)] = data;
    (*stack_count)++;
}

// .......... Pop Function .............
int pop(int *stack, int *stack_count, int *top_indx){
    if(*stack_count==0){
        printf("\n!!! Stack Underflow !!!\n");
        return -1;
    }
    if(*top_indx<0){
        *top_indx = MAX_STACK_SIZE - 1;
    }
    int data = stack[(*top_indx)--];
    (*stack_count)--;

    return data;
}

// ............... Main Function ...................
int main(){
    int stack[MAX_STACK_SIZE], stack_count = 0, top_indx = -1,data;
    int operation;

    while(1){
        operations();
        print_stack(stack,stack_count);

        printf("\nOperaton: ");
        scanf("%d",&operation);

        if(operation==0){
            break;
        }
        else if(operation==1){
            printf("Data to push: ");
            scanf("%d",&data);
            push(stack,data,&stack_count,&top_indx);
        }
        else if(operation==2){
            data = pop(stack,&stack_count,&top_indx);
        }
        else{
            printf("\nInvalid Operation !!!\n");
        }
    }

    printf("\nProgram exited successfully.\n");

    return 0;
}