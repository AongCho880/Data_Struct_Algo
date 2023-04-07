// ................ Counting Sort with C ............

#include<stdio.h>
#include<stdlib.h>

// Get data from "count_sort.txt" file ......
int *read_file(int *size){
    FILE *fptr = fopen("count_sort.txt","r");
    if(fptr==NULL){
        return NULL;
    }

    fscanf(fptr,"%d",size);

    int *arr = (int *)calloc(*size,sizeof(int)); // memory allocation
    for(int i=0;i<*size;i++){
        fscanf(fptr,"%d",&arr[i]);
    }
    fclose(fptr);
    return arr;
}

// Counting Sort ............
void counting_sort(int *arr, int size){
    int max = arr[0];

    // Find the max element
    for(int i=0;i<size;i++){
        if(max<arr[i]){
            max = arr[i];
        }
    }

    // Memory allocation
    int *count = (int *)calloc(max+1,sizeof(int));
    int *output = (int *)calloc(size,sizeof(int));

    // Count the number of occurance of each element
    for(int i=0;i<size;i++){
        count[arr[i]]++;
    }

    // Compute the prefix sum
    for(int i=1;i<=max;i++){
        count[i] += count[i-1];
    }

    // Place the elements in the sorted order
    for(int i=size-1;i>=0;i--){
        output[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted elements to the original array
    for(int i=0;i<size;i++){
        arr[i] = output[i];
    }

    free(count);
    free(output);
}

// Main Function .........
int main(){
    int size=0;
    int *arr = read_file(&size);

    if(arr==NULL){
        printf("\nUnable to create array !!!\n");
        return 0;
    }

    printf("Unsorted: ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    
    counting_sort(arr,size);

    printf("\nSorted: ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }

    free(arr);
    return 0;
}

// ...... Time Complexity .......
// Find max      : O(n)
// Count elements: O(n)
// Prefix sum    : O(k)   [k = range of element]
// Sort elements : O(n)
// Copy elements : O(n)
// ----------------------
// Complexity    : O(n+k)