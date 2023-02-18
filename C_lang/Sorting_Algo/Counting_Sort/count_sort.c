#include<stdio.h>
#include<stdlib.h>


// Read data from count_sort.txt file ..........
int *read_file(int *size, int *mx){
    FILE *fptr = fopen("count_sort.txt","r");
    if(fptr==NULL){
        return NULL;
    }
    else{
        fscanf(fptr,"%d",size);
        int *arr = calloc(*size,sizeof(int)); // allocate memory for arr
        for(int i=0;i<*size;i++){
            fscanf(fptr,"%d",&arr[i]);
            if(arr[i]>*mx){
                *mx = arr[i];   // update max data if arr[i] is greater
            } 
        }
        fclose(fptr);

        return arr;
    }
}

// .............. Counting Sort ...................
int *count_sort(int *arr, int size, int mx){
    int *count = calloc(mx+1,sizeof(int));
    
    for(int i=0;i<size;i++){
        count[arr[i]]++;
    }

    for(int i=1;i<mx+1;i++){
        count[i] += count[i-1];
    }

    int *output = calloc(size,sizeof(int));
    for(int i=size-1;i>=0;i--){
        output[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }

    return output;
}


// ............ Maing Function .............
int main(){
    int size=0,mx=0;
    int *arr = read_file(&size,&mx);

    if(arr==NULL){
        printf("File doesn't exist!\n");
        return 1;
    }
    else{
        int *output = count_sort(arr,size,mx);

        printf("Raw data:\n");
        for(int i=0;i<size;i++){
            printf("%d ",arr[i]);
        }

        printf("\nSorted data:\n");
        for(int i=0;i<size;i++){
            printf("%d ",output[i]);
        }
        
        free(arr); free(output);

        return 0;
    }
}