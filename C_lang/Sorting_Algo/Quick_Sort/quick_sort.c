// ........... Quick Sort with C ...............

#include<stdio.h>
#include<stdlib.h>

// Get input from "test.txt" file ..............
int *read_file(int *size){
    FILE *fptr = fopen("quick_sort.txt","r");
    
    if(fptr == NULL){
        return NULL;
    }

    fscanf(fptr,"%d",size);
    int *arr = (int *)calloc(*size,sizeof(int));
    for(int i=0;i<*size;i++){
        fscanf(fptr,"%d",&arr[i]);
    }

    fclose(fptr);

    return arr;
}

// Swap Function ............
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Make Partition ..............
int partition(int *arr,int lwb, int upb){
    int pivot = arr[upb];
    int i = lwb;
    for(int j=lwb; j<upb;j++){
        if(arr[j]<pivot){
            swap(&arr[i],&arr[j]);
            i++;
        }
    }
    swap(&arr[i],&arr[upb]);
    return i;
}

// Quick Sort ................
void quick_sort(int *arr, int lwb, int upb){
    if(lwb<upb){
        int p = partition(arr,lwb,upb);
        quick_sort(arr,lwb,p-1);
        quick_sort(arr,p+1,upb);
    }
}

// Main Function ..................
int main(){
    int size=0;
    int *arr = read_file(&size);

    printf("Unsorted: ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }

    quick_sort(arr,0,size-1);
    
    printf("\nSorted: ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }

    free(arr);
    return 0;
}

// ........ Time Complexity ...........
// Best Case        Worst Case
//  O(n*log(n))       O(n*n)