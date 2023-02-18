#include<stdio.h>
#include<stdlib.h>

// ......... Get input from bubble_sort.txt file ...........
void read_file(int *arr, int *size){
    FILE *fptr = fopen("bubble_sort.txt","r");
    if(fptr==NULL){
        printf("File doesn't exist !\n");
    }
    else{
        fscanf(fptr,"%d",size);
        for(int i=0;i<*size;i++){
            fscanf(fptr,"%d",&arr[i]);
        }
        fclose(fptr);
    }
}

// ............. Swap function ..............
void swap(int *a, int *b){
    int temp=*a;
    *a = *b;
    *b = temp;
}

// ................ Bubble Sort .............
void bubble_sort(int *arr, int size){
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1])
                swap(&arr[j],&arr[j+1]);
        }
    }
}

// ........... Main Function ............
int main(){
    int size;
    int *arr = (int *)malloc(100*sizeof(int)); // Memory allocation for the arr
    read_file(arr,&size);
    bubble_sort(arr,size);
    for(int i=0;i<size;i++)
        printf("%d ",arr[i]);
    
    free(arr); // Memory deallocation
    return 0;
}