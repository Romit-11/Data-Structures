#include<iostream>
using namespace std;

// Function to sort array.
void selectionSort(int *a, int n){
    // Loop for passing;
    for(int i =0; i<n-1; i++){
        int minIndex = i;
        //Loop for finding index of minimum element;
        for(int j = i+1; j<n; j++){
            if(a[j]<a[minIndex]){
                minIndex = j;
            }
        }
        // Swapping the element at ith index with minimum element;
        int temp = a[i];
        a[i]=a[minIndex];
        a[minIndex] = temp;
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
    int arr[] = {8,1,7,10,5};
    int n =sizeof(arr)/4; //size of array.
    // array before sorting.
    printArray(arr, n);

    // array after sorting.
    selectionSort(arr, n);
    printArray(arr, n);
    
    return 0;
}