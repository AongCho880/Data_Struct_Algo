#include<stdio.h>
#include<stdlib.h>

// ......... Get input from bubble_sort.txt file ...........
int *read_file(int *size){
    FILE *fptr = fopen("bubble_sort.txt","r");
    if(fptr==NULL){
        return NULL;
    }
    else{
        fscanf(fptr,"%d",size);
        int *arr = (int *)malloc(*size*sizeof(int)); // Dynamically memory allocation
        for(int i=0;i<*size;i++){
            fscanf(fptr,"%d",&arr[i]);
        }
        fclose(fptr);
        return arr;
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
        int swaped = 0;
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                swaped = 1;
            }
        }
        if(swaped==0){ // swaped=0; means that array is alrady sorted
            break;
        }
    }
}

// ........... Main Function ............
int main(){
    int size;
    int *arr = read_file(&size);
    if(arr==NULL){
        printf("File doesn't exist !\n");
        return 1;
    }
    bubble_sort(arr,size);
    for(int i=0;i<size;i++)
        printf("%d ",arr[i]);
    
    free(arr); // Memory Deallocation
    return 0;
}