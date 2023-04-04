#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <random>
using namespace std;
using namespace std::chrono;

// Function to swap two elements in an array
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Function to partition the array and return the partition index
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Recursive QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    // Seed random number generator
    srand(time(NULL));

    const int SIZE = 30000;
    int arr[SIZE];

    // Generate random numbers and fill the array
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100; // Generate a random number between 0 and 99
    }

    // Print the unsorted array
    /*cout << "Unsorted array:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;*/

    cout<<"Array Size: " << SIZE<<endl;

    auto start_time = high_resolution_clock::now();
    // Sort the array using QuickSort
    quickSort(arr, 0, SIZE - 1);
    auto end_time = high_resolution_clock::now();
    auto execution_time = duration_cast<microseconds>(end_time - start_time);
    cout << "Execution time: " << execution_time.count() << " us" << endl;
    

    // Print the sorted array
    /*cout << "Sorted array:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;*/

    return 0;
}
