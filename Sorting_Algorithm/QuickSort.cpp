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

// Function to partite the array so that in left of pivot there are all smaller elements and in right there are all greater elements.
int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (a[i] <= pivot)
        {
            i++;
        }

        while (a[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);

    temp = a[low];
    a[low]=a[j];
    a[j]=temp;
    return j;
}

// Function for sorting algorithm.
void quickSort(int a[], int low, int high)
{
    int partitionIndex;
    if (low < high)
    {
        partitionIndex = partition(a, low, high); // index of pivot after partition.
        quickSort(a, low, partitionIndex - 1);    // Sort left subarray.
        quickSort(a, partitionIndex + 1, high);   // Sort right subarray.
    }
}



int main()
{

    int arr[] = {8, 1, 7, 10, 5, 14, 5, 15, 1};
    int n = sizeof(arr) / 4; // size of array.
    // array before sorting.
    printArray(arr, n);

    // array after sorting.
    quickSort(arr, 0, n - 1);
    printArray(arr, n);

    return 0;
}