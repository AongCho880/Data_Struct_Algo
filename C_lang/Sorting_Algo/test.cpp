// Assignment-2: Sort the name of n students with a linear time complexity

#include<bits/stdc++.h>
using namespace std;

char charAt(string name, int index){
    return name[index];
}

void countSort(string name[],int totalNm,int index, char lower, char upper){
    int totalChar = (upper-lower)+1;
    int countChar[totalChar] = {0};
    string tempNm[totalNm];

    // Counting Counting
    for(int i=0;i<totalNm;i++){
        int charIndex = (name[i].length()-1<index) ? 0 : (charAt(name[i],index)-lower);
        countChar[charIndex]++;
    }

    // Cumulative Sum
    for(int i=1;i<totalChar;i++)
        countChar[i] += countChar[i-1];
    
    // Sorting Names in a Temporary string array 
    for(int i=totalNm-1;i>=0;i--){
        int charIndex = (name[i].length()-1<index)? 0 : (charAt(name[i],index)-lower);
        tempNm[countChar[charIndex]-1] = name[i];
        countChar[charIndex]--;
    }

    // Copying Sorted Names to Original array
    for(int i=0;i<totalNm;i++)
        name[i] = tempNm[i];
    
}


void radixSort(string name[], int totalNm,int maxNmLn, char lower, char upper){
    for(int index=maxNmLn; index>=0; index--){
        countSort(name,totalNm,index,lower,upper);
    }
}


int InputName(string name[], int totalNm){
    int maxNmLn = 0;
    for(int i=0;i<totalNm;i++){
        cout << i+1 << ". ";
        fflush(stdin);
        getline(cin,name[i]);
        int n = name[i].length();
        maxNmLn = max(maxNmLn,n);
    }
    return maxNmLn-1;
}

int main(){
    int totalNm;
    cout << "Total Name: "; cin >> totalNm;
    string name[totalNm];

    int maxNmLn = InputName(name,totalNm);

    radixSort(name,totalNm,maxNmLn,' ','z');

    cout << "\nSorted Name:\n";
    for(int i=0;i<totalNm;i++)
        cout << i+1 << ". " << name[i] << "\n";
        cout << "\n";

    return 0;
}