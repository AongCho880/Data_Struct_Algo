// ....... Binary Search Tree ...........
// .......... Main Function .............

#include <iostream>
#include "bst.h"
using namespace std;

int main(){
    Node *root = nullptr;
    
    printf("\nNumber of node: ");
    int n; cin >> n;

    // Data insertion .......
    cout << "Insert data: ";
    for(int i=0;i<n;i++){
        int data; cin >> data;
        root = insert_in_bst(root,data);
    }

    // Pre_Order Sequence .......
    cout << "\nPre_order Sequence: ";
    pre_order(root);

    // In_Order Sequence ........
    cout << "\nIn_order Sequence: ";
    in_order(root);

    // Post_order Sequence ......
    cout << "\nPost_order Sequence: ";
    post_order(root);

    return 0;

}