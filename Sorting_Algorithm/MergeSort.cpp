#include <iostream>
using namespace std;

// Function to print array.
void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}

// Function to merge the sorted array.
void merge(int a[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int b[high + 1];
    int k = low;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        k++;
        i++;
    }

    while (j <= high)
    {
        b[k] = a[j];
        k++;
        j++;
    }

    for (i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
}

// Recursive function to divide the array into subarrays and also call the merging function to remerge them.
void mergeSort(int a[], int low, int high)
{

    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main()
{
    int arr[] = {8, 1, 7, 10, 5, 14, 5, 15, 1};
    int n = sizeof(arr) / 4; // size of array.
    // array before sorting.
    printArray(arr, n);

    // array after sorting.
    mergeSort(arr, 0, n - 1);
    printArray(arr, n);
    return 0;
}