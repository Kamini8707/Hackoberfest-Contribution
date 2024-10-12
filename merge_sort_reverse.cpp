// File: merge_sort_reverse.cpp
// Description: C++ implementation of Merge Sort with ascending/descending order option
// Author: [Your Name]
// License: Open Source

#include <iostream>
using namespace std;

// Function to merge two subarrays
void merge(int array[], int const left, int const mid, int const right, bool ascending) {
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];

    // Copy data to temp arrays
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    // Merge the temp arrays back into the original array
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (ascending) {
            if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
                array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            } else {
                array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
        } else {
            if (leftArray[indexOfSubArrayOne] >= rightArray[indexOfSubArrayTwo]) {
                array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            } else {
                array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
        }
        indexOfMergedArray++;
    }

    // Copy remaining elements of left array, if any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    // Copy remaining elements of right array, if any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }

    delete[] leftArray;
    delete[] rightArray;
}

// Recursive function to implement merge sort with an ascending/descending option
void mergeSort(int array[], int const begin, int const end, bool ascending) {
    if (begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid, ascending);
    mergeSort(array, mid + 1, end, ascending);
    merge(array, begin, mid, end, ascending);
}

// Function to print an array
void printArray(int array[], int size) {
    for (auto i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

// Driver code
int main() {
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    auto arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is:\n";
    printArray(arr, arr_size);

    char orderChoice;
    cout << "Enter 'a' for ascending or 'd' for descending order: ";
    cin >> orderChoice;
    bool ascending = (orderChoice == 'a');

    mergeSort(arr, 0, arr_size - 1, ascending);

    cout << "Sorted array is:\n";
    printArray(arr, arr_size);

    return 0;
}
