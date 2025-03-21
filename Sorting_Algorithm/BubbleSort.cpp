#include<iostream>
using namespace std;

void bubbleSort(int *a, int n){
    int isSorted = 0;
    for(int i =0; i<n-1; i++){
        isSorted = 1;
        cout<<"This is the "<<i+1<<"th number of pass."<<"\n";
        for(int j = 0; j<n-1-i; j++){
            if(a[j]>a[j+1]){
                int temp = a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
                isSorted = 0;
            }
        }
        if(isSorted){
            return;
        }
    }
}

void printArray(int *a, int n){
    for(int i =0; i<n; i++){
        cout<<a[i]<<" ";
    }
}

int main(){
    // int arr[] = {10, 8, 20, 25, 4, 1};
    int arr[] = {1,2,100,46,50,90};
    int n = 6;
    printArray(arr, n);
    cout<<"\n";
    bubbleSort(arr, n);
    printArray(arr, n);
    return 0;
}