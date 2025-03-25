#include<iostream>
using namespace std;

// Function for sorting array.
void insertionSort(int* a, int n){
    int key;
    int j = 1;
    //Loop for each paas.
    for(int i = 1; i<n; i++){
        key = a[i];
        j=i-1;

        // Loop for sorted array.
        while (a[j]>key && j>=0)
        {
            a[j+1]=a[j]; //if the value of key is smaller then the element at jth postion then the element at the jth position in moved one step right;
            j--;
        }
        a[j+1]=key;
        
    }
}

// Function to print array.
void printArray(int *a, int n){
    for(int i =0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

int main(){

    int arr[] = {1,2,100,46,50,90};
    int n = 6; //size of array.
    // array before sorting.
    printArray(arr, n);

    // array after sorting.
    insertionSort(arr, n);
    printArray(arr, n);
    
    return 0;
}