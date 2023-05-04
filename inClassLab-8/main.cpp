#include <iostream>

using namespace std;


void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    cout << "Enter the numbers which need to be sorted " << endl;
    cout << "Press E to stop taking inputs " << endl;

    int arr[100]; // initialize an array of size 100

    // take user inputs and add them to the array
    string input;
    int i = 0;
    while (cin >> input) {
        if (input == "E") {
            break; // stop taking user inputs if "E" is entered
        }
        int num = stoi(input); // convert input to integer
        arr[i] = num;
        i++;
    }
    int n = i;

    cout << "Input array: ";
    for (int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
