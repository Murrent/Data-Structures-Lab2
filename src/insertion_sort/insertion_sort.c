//
// Created by Martin on 2021-02-22.
//

#include "insertion_sort.h"
#include "../console/console.h"
#include <stdio.h>

void insertion_sort(int* array) {
    size_t n = array[0] + 1;
    for (size_t j = 1; j < n; ++j) {
        int key = array[j];
        size_t i = j - 1;
        while (i > 0 && array[i] > key) {
            array[i + 1] = array[i];
            i = i - 1;
            plotArray(array, (int)n-1);
        }
        array[i + 1] = key;
    }
}