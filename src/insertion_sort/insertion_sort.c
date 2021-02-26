//
// Created by Martin on 2021-02-22.
//

#include "insertion_sort.h"
#include "../console/console.h"
#include <stdio.h>

/**
 * Insertion sort loops through the array and for each element it loops backwards from it's spot to find the appropriate
 * spot for the element.
 * @param array
 */
void insertionSort(int* array) {
    size_t n = array[0] + 1;
    for (size_t j = 1; j < n; ++j) {
        int key = array[j];
        size_t i = j - 1;
        while (i > 0 && array[i] > key) {
            array[i + 1] = array[i];
            i = i - 1;
        }
        array[i + 1] = key;
    }
}
/**
 * Insertion sort with graph.
 * @param array
 */
void insertionSortGraphed(int* array) {
    size_t n = array[0] + 1;
    for (size_t j = 1; j < n; ++j) {
        plotArray(array, (int)n, j);
        int key = array[j];
        size_t i = j - 1;
        while (i > 0 && array[i] > key) {
            plotArray(array, (int)n, (int)i);
            array[i + 1] = array[i];
            i = i - 1;
        }
        array[i + 1] = key;
    }
    plotArray(array, (int)n, 0);
}