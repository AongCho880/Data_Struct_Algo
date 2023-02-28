// ....... Implement Quick Sort in C ...........
// ............ Aong Cho Marma .................

#include<stdio.h>

// Swap Function .................
void swap(int arr[],int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Make Partition ....................
int partition(int arr[], int p, int r){
    int x = arr[r];
    int i = p;
    for(int j=p;j<r;j++){
        if(arr[j]<=x){
            swap(arr,i,j);
            i++;
        }
    }
    swap(arr,i,r);

    return i;
}

// Quick Sort ..................
void quick_sort(int arr[], int p, int r){
    if(p<r){
        int q = partition(arr,p,r);
        quick_sort(arr,p,q-1);
        quick_sort(arr,q+1,r);
    }
}

// Main Function ..........
int main(){

    int arr[] = {2,8,7,1,3,5,6,4};
    int size = sizeof(arr)/sizeof(arr[0]);

    quick_sort(arr,0,size-1);

    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}