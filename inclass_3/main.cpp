#include <iostream>
#include <iterator>
#include <chrono>
using namespace std;
using namespace std::chrono;


//recursive implementation
int partition_recursive(int arr[], int start, int end)
{

    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }


    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (arr[i] <= pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort_recursive(int arr[], int start, int end)
{

    if (start >= end)
        return;

    int p = partition_recursive(arr, start, end);

    quickSort_recursive(arr, start, p - 1);

    quickSort_recursive(arr, p + 1, end);
}

// iterative implementation

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition_iterative(int arr[], int l, int h)
{
    int x = arr[h];
    int i = (l - 1);

    for (int j = l; j <= h - 1; j++) {
        if (arr[j] <= x) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return (i + 1);
}

void quickSort_iterative(int A[], int l, int h)
{
    if (l < h) {
        /* Partitioning index */
        int p = partition_iterative(A, l, h);
        quickSort_iterative(A, l, p - 1);
        quickSort_iterative(A, p + 1, h);
    }
}



int main()
{
    int sz;
    cout << "Enter the size of array::";
    cin >> sz;

    int copy_1[sz];
    int copy_2[sz];

    for(int i=0;i<sz;i++){
        int temp_val=rand()%100;
        copy_1[i] = temp_val;
        copy_2[i] = temp_val;
    }
    int len = sizeof(copy_1)/sizeof(copy_1[0]);

    //get time for recursive
    auto start_r = high_resolution_clock::now();
    quickSort_recursive(copy_1,0,len-1);
    auto stop_r = high_resolution_clock::now();
    auto duration_r = duration_cast<microseconds>(stop_r - start_r);
    cout << "recursive function : " << duration_r.count() << endl;
    // get time for iterative
    auto start_I = high_resolution_clock::now();
    quickSort_iterative(copy_2,0,len-1);
    auto stop_I = high_resolution_clock::now();
    auto duration_I = duration_cast<microseconds>(stop_I - start_I);
    cout << "Iterative function : " << duration_I.count() << endl;

}




