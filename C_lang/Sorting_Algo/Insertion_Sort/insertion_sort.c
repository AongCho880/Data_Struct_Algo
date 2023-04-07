// ........... Insertion Sort .............
#include<stdio.h>
#include<stdlib.h>

// Get data from "insertion_sort.txt" file ..........
int *read_data(int *size){
    FILE *fptr = fopen("insertion_sort.txt","r");
    if(fptr==NULL){
        return NULL;
    }

    fscanf(fptr,"%d",size);
    int *arr = (int *)malloc(*size*sizeof(int));
    for(int i=0;i<*size;i++){
        fscanf(fptr,"%d",&arr[i]);
    }
    fclose(fptr);
    return arr;
}

// Insertion Sort ...............
void insertion_sort(int *arr, int size){
    for(int i=1;i<size;i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// Main Function ...........
int main(){
    int size;
    int *arr = read_data(&size);
    if(arr == NULL){
        printf("\nUnable to create data list !!!\n");
        return 0;
    }
    printf("Raw data: ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }

    insertion_sort(arr,size);
    printf("\nSorted data: ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}