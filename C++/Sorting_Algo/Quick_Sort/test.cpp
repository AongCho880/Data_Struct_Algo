// .............. Quick Sort Implementation in C++ ...................
// ........................ Aong Cho Marma ............................. 

#include<iostream>
using namespace std;

// Make partition ....................
int partition(int arr[], int p, int r){
    int x = arr[r];
    int i = p;
    for(int j=p;j<r;j++){
        if(arr[j]<=x){
            swap(arr[i],arr[j]);
            i++;
        }
    }
    swap(arr[i],arr[r]);

    return i;
}

// Quick Sort ...........................
void quick_sort(int arr[], int p, int r){
    if(p<r){
        int q = partition(arr,p,r);
        quick_sort(arr,p,q-1);
        quick_sort(arr,q+1,r);
    }
}

// Main Function .............
int main(){
    int arr[] = {2, 4, 7, 1, 3, 5, 6, 4};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    quick_sort(arr,0,size-1);

    for(int i=0;i<size;i++)
        cout << arr[i] << " ";
    
    cout << "\n";

    return 0;
}