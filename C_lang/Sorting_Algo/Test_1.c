#include <stdio.h>
#include <stdlib.h>

int *count_sort(int *arr, int size, int mx){
    int *count = calloc(mx+1,sizeof(int));
    
    for(int i=0;i<size;i++){
        count[arr[i]]++;
    }

    for(int i=1;i<mx+1;i++){
        count[i] += count[i-1];
    }

    int *output = calloc(size,sizeof(int));
    for(int i=0;i<size;i++){
        output[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }
    free(count);
    return output;
}


int main() {
    int arr[] = {5,5,2,1,3,3,7,1,2,3};
    int size = 10, mx = 7;

    int *out = count_sort(arr,size,mx);

    for(int i=0;i<size;i++)
        printf("%d ",out[i]);
    free(out);
    return 0;
}
