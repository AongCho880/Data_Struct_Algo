#include<bits/stdc++.h>
using namespace std;

int partition(int A[], int p, int r){
    int x = A[r];
    int i = p-1;
    for(int j=p;j<r;j++){
        if(A[j]<=x){
            i++;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);

    return i+1;
}

void quick_sort(int A[], int p, int r){
    int q;
    if(p<r){
        q = partition(A,p,r);
        quick_sort(A,p,q-1);
        quick_sort(A,q+1,r);
    }
}

int main(){
    int A[] = {2,8,7,1,3,5,6,4};
    int r = 8;
    quick_sort(A,0,r-1);

    for(int i=0;i<r;i++)
        cout << A[i] << " ";

    return 0;
 }