#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std;
using namespace std::chrono;

void insertionSort(vector<int>& vec);
void bubbleSort(vector<int>& vec);
void Optimized_bubbleSort(vector<int>& vec);
void selectionSort(vector<int>& vec);

int main()

{
    vector<int> times;
    vector<int> values(20000);
    auto f = []() -> int { return rand() % 10000; };
    generate(values.begin(), values.end(), f);
    vector<int> arr_1 = values;
    vector<int> arr_2 = values;
    vector<int> arr_3 = values;
    vector <int> arr_4 = values;
    auto beg_1 = high_resolution_clock::now();
    bubbleSort(arr_1);
    auto end_1 = high_resolution_clock::now();
    auto duration_1 = duration_cast<microseconds>(end_1 - beg_1);
    times.push_back(duration_1.count());
    auto beg_2 = high_resolution_clock::now();
    Optimized_bubbleSort(arr_2);
    auto end_2 = high_resolution_clock::now();
    auto duration_2 = duration_cast<microseconds>(end_2 - beg_2);
    times.push_back(duration_2.count());
    auto beg_3 = high_resolution_clock::now();
    selectionSort(arr_3);
    auto end_3 = high_resolution_clock::now();
    auto duration_3 = duration_cast<microseconds>(end_3 - beg_3);
    times.push_back(duration_3.count());
    auto beg_4 = high_resolution_clock::now();
    insertionSort(arr_4);
    auto end_4 = high_resolution_clock::now();
    auto duration_4 = duration_cast<microseconds>(end_4 - beg_4);
    times.push_back(duration_4.count());

    for (int i = 0 ; i < 4 ; i++){
        cout << times[i] << endl;
    }
}

void insertionSort(vector<int>& vec) {
    int n = vec.size();
    for (int i = 1; i < n; i++) {
        int key = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > key) {
            vec[j+1] = vec[j];
            j--;
        }
        vec[j+1] = key;
    }
}

void bubbleSort(vector<int>& vec) {
    bool swapped;
    int n = vec.size();
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (vec[j] > vec[j+1]) {
                swap(vec[j], vec[j+1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

void Optimized_bubbleSort(vector<int>& vec) {
    bool swapped;
    int n = vec.size();
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (vec[j] > vec[j+1]) {
                swap(vec[j], vec[j+1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}
void selectionSort(vector<int>& vec) {
    int n = vec.size();
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (vec[j] < vec[min_idx]) {
                min_idx = j;
            }
        }
        swap(vec[i], vec[min_idx]);
    }
}


