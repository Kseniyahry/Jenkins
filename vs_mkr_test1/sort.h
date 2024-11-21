#ifndef SORT
#define SORT
#include "stringProcessor.h"
#include <stddef.h>
#include <string.h>
// Helper function to swap two strings
void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
size_t partition(char **arr, size_t low, size_t high) {
    char *pivot = arr[high]; // Choose the last element as the pivot
    size_t i = low;          // Index for the smaller element

    for (size_t j = low; j < high; j++) {
        if (strcmp(arr[j], pivot) < 0) { // Compare strings lexicographically
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]); // Place pivot at the correct position
    return i;
}

// Quick Sort recursive function
void quick_sort_recursive(char **arr, size_t low, size_t high) {
    if (low < high) {
        size_t pivot_index = partition(arr, low, high);

        // Recursively sort elements before and after the partition
        if (pivot_index > 0) { // Prevent underflow for size_t
            quick_sort_recursive(arr, low, pivot_index - 1);
        }
        quick_sort_recursive(arr, pivot_index + 1, high);
    }
}

// Quick Sort main function
void quick_sort(char **arr, size_t length) {
    if (!arr || length <= 1) {
        return; // No sorting needed for NULL or single-element arrays
    }
    quick_sort_recursive(arr, 0, length - 1);
}
#endif // !SORT