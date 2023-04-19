// Insertion-Sort With C++ ..............

#include<iostream>
#include<fstream>

using namespace std;

// Get data from "data.txt" file ..........
int* read_data(int &size) {
    ifstream infile("data.txt");
    if(!infile.is_open()) {
        return nullptr;
    }

    // get array size from the file
    infile >> size; 

    // Dynamically memory allocate
    int* arr = new int[size];

    for(int i=0;i<size;i++) {
        infile >> arr[i];
    }

    infile.close();
    return arr;
}

// Insertion-Sort ..............
void insertionSort(int* arr, int size) {
    for(int j=1; j<size;j++) {
        int key = arr[j];
        int i = j-1;
        while(i>=0 and arr[i]>key) {
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = key;
    }
}

// Print function ..........
void print(int* arr, int size) {
    for(int i=0;i<size;i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

// Main Function .................
int main() {
    int size;
    int* arr = read_data(size);

    if(arr==nullptr) {
        cout << "\nUnable to create data list !!!\n";
        return 0;
    }

    cout << "Unsorted data: ";
    print(arr, size);
    insertionSort(arr, size);
    cout << "Sorted data: ";
    print(arr,size);

    return 0;
}