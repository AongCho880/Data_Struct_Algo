// ...... Bubble Sort Implementation with C++ .........

#include<iostream>
using namespace std;

// Bobble sort function .............
void bubble_sort(int *arr, int size){
    for(int i=0;i<size-1;i++){
        bool swaped = false;
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swaped = true;
            }
        }
        if(swaped == false) // swaped false means, already sorted;
            break;
    }
}

// Main Function ..........
int main(){
    int arr[] = {4,3,1,5,6,7,3,4};
    bubble_sort(arr,sizeof(arr)/sizeof(arr[0]));
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
        cout << arr[i] << " ";

    return 0;
}