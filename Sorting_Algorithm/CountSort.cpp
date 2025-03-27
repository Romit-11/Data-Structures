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

// Function to sort array.
void countSort(int *a, int n)
{
    int i = 0;
    int max = a[0];

    for (i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }

    int b[max + 1]; // Assigining auxiliary array of size 'Max element+1'.

    // Loop for assigining values of auxiliary equal to zero.
    for (i = 0; i <= max; i++)
    {
        b[i] = 0;
    }

    // Loop for assiginging values(incrimenting from 0) of auxiliary array at the index equal to the element of given array.
    for (i = 0; i < n; i++)
    {
        b[a[i]] = b[a[i]] + 1;
    }

    i = 0;
    int j = 0;

    // Loop for assiging elements of given array equal to the index of auxiliary array.
    while (i <= max)
    {
        if (b[i] > 0)
        {
            a[j] = i;
            b[i] = b[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
}

int main()
{

    int arr[] = {8, 1, 7, 10, 5, 14, 5, 15, 1};
    int n = sizeof(arr) / 4; // size of array.
    // array before sorting.
    printArray(arr, n);

    // array after sorting.
    countSort(arr, n);
    printArray(arr, n);
    return 0;
}