// ......... Implementation of Queue with Array ............
// .................. Main Function ........................
// .......... Author: Aong Cho Marma .......................

#include<stdio.h>
#include "q_arr.h"

#define MX_QUE_SIZE 10

int main(){
    int que[MX_QUE_SIZE];
    int q_count=0, head = 0, tail = -1;
    int operation;

    while(1){
        operations();
        print_que(que,MX_QUE_SIZE,head,q_count);
        printf("\n> Operation: ");
        scanf("%d",&operation);
        if(operation==0)
            break;
        execute_operation(que,MX_QUE_SIZE,&head,&tail,&q_count,operation);
    }

    printf("\nProgram Exited.\n");

    return 0;
}