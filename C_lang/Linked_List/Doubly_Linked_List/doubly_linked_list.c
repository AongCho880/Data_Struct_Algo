// ......... Doubly Function Definitions .........
// ......... Author: Aong Cho Marma ..............

#include<stdio.h>
#include<stdlib.h>
#include"doubly_L.h"

// Operations ..............................
void operations(){
    printf("\n.......... Operations ..........\n");
    printf("1. Insert at\n");
    printf("2. Delete a node\n");
    printf("3. Search key\n");
    printf("4. Clear List\n");
    printf("0. Exit Program\n");
}

// Create a node .............................
Node *create_node(int data){
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;

    return node;
}

// Create an initial list ...................
void create_list(Node **head, Node **tail, int *count){
    printf("Input data (-1 to end input):\n> ");
    int data;
    while(1){
        scanf("%d",&data);
        if(data==-1){
            return;
        }
        Node *new_node = create_node(data);
        if(*tail==NULL && *head==NULL){
            *tail = new_node;
            *head = new_node;
        }
        else{
            new_node->next = *head;     // link current head node as a next node of new node
            (*head)->prev = new_node;   // link new node with current head node
            *head = new_node;           // new_node is head node now
        }
        (*count)++;
    }
}

// Insert at index ......................................
void insert_at(Node **head, Node **tail, int indx, int data, int *count){
    Node *new_node = create_node(data);
    if(indx==0){    // Insert at head
        new_node->next = *head;     // link current head node as a next node of new node
        (*head)->prev = new_node;   // link new node with current head node
        *head = new_node;           // new_node is head node now
        (*count)++;
        return;
    }
    int i=0;
    Node *current_node = *head;
    while(i!=indx){
        if(current_node==NULL){
            printf("\nInvalid position !\n");
            return;
        }
        current_node = current_node->next;
        i++;
    }
    if(current_node == NULL){  // Insert at tail
        new_node->prev = *tail;
        (*tail)->next = new_node;
        *tail = new_node;
        (*count)++;
        return;
    }

    new_node->next = current_node;
    new_node->prev = current_node->prev;
    current_node->prev->next = new_node;
    current_node->prev = new_node;
    (*count)++;

}

// Delete a node ...................................
int delete_node(Node **head, Node **tail, int data, int *count){
    Node *current_node = *head;
    while(current_node!=NULL){
        if(current_node->data==data){
            break;
        }
        current_node = current_node->next;
    }
    if(current_node->prev==NULL){   // Delete head node
        data = current_node->data;
        *head = current_node->next;
        free(current_node);
        (*count)--;
        return data;
    }
    else if(current_node->next == NULL){    // Delete tail node
        data = current_node->data;
        *tail = current_node->prev;
        (*tail)->next = NULL;
        free(current_node);
        (*count)--;
        return data;
    }
    else if(current_node!=NULL){    // Delete node between head and tail
        data = current_node->data;
        current_node->prev->next = current_node->next;
        current_node->next->prev = current_node->prev;
        free(current_node);
        (*count)--;
        return data;
    }
    return -1;
}

// Search key........................
int search_key(Node **head, int key){
    Node *node = *head;
    while(node!=NULL){
        if(node->data==key){
            printf("\nKey found ...\n");
            return 0;
        }
    }
    printf("\nKey doesn't found !\n");
    return -1;
}

// Traverse List ....................
void traverse(Node *head, int count){
    printf("List: ");
    while(head!=NULL){
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\nData_count: %d\n",count);
}

// Clear List ......................
void clear_list(Node **head){
    Node *node = NULL;
    while((*head)!=NULL){
        node = *head;
        *head = (*head)->next;
        free(node);
    }
}

// Execute Operation .....................................................
void execute_operation(Node **head, Node **tail, int *count, int operation){
    if(operation==1){
        printf("Data to push: ");
        int data; scanf("%d",&data);
        printf("Index: ");
        int indx; scanf("%d",&indx);
        insert_at(head,tail,indx,data,count);
    }
    else if(operation==2){
        printf("Data to delete: ");
        int data; scanf("%d",&data);
        data = delete_node(head,tail,data,count);
    }
    else if(operation==3){
        printf("Key to search: ");
        int key; scanf("%d",&key);
        search_key(head,key);
    }
    else if(operation==4){
        clear_list(head);
        *count = 0;
    }
    else
        printf("\nInvalide operation !!!\n");
}
