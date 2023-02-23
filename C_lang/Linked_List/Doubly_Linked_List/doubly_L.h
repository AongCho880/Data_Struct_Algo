// ........ Doubly Header file .............
// ........ Author: Aong Cho Marma .........

#ifndef doubly_L    // Check if the header file is defined earlier
#define doubly_L

// Define structure .......................
typedef struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
}Node;

// Operations ..............................
void operations();

// Create a node ...........................
Node *create_node(int data);

// Create an initial list ..................
void create_list(Node **head, Node **tail, int *count);

// Insert at index ........................
void insert_at(Node **head, Node **tail, int indx, int data, int *count);

// Delete a node ..........................
int delete_node(Node **head, Node **tail, int data, int *count);

// Search key..............................
int search_key(Node **head, int key);

// Traverse List ..........................
void traverse(Node *head, int count);

// Clear List .............................
void clear_list(Node **head);

// Execute Operation ......................
void execute_operation(Node **head, Node **tail, int *count, int operation);

#endif
