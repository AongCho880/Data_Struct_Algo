// Insertion-Sort with C .....................
#include<stdio.h>
#include<stdlib.h>

// Insert-Sort Function ............
void insertionSort(int A[], int n) {
    for(int j=1;j<n;j++) {
        int key = A[j];
        // Insert A[j] into the sorted sequence A[0:j-1]
        int i = j-1;
        while(i>=0 && A[i]>key) {
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
}

// Print array .......
void print(int A[], int n) {
    for(int i=0;i<n;i++) {
        printf("%d ",A[i]);
    }
}

// Main Function .....
int main() {
    int A[] = {5,2,4,6,1,3};
    int n = sizeof(A)/sizeof(A[0]);
    
    printf("\nBefore sort: ");
    print(A,n);
    insertionSort(A,n);
    printf("\nAfter sort: ");
    print(A,n);

    return 0;
}