//
// Created by Martin on 2021-02-23.
//

#include <stdio.h>

#include "../load_files/load_file.h"
#include "../insertion_sort/insertion_sort.h"

/**
 * This program takes the filepath from argc[1], loads the file and adds it's content into an integer array.
 * First, the input array is printed. We then sort the array with insertion sort and print the sorted array;
 * @param argc
 * @param argv
 * @return
 */
int main( int argc, char* argv[] )
{
    const char* fName = argv[1];

    int* a = load_file(fName);

    int size = a[0];
    printf("Input array:\n");
    for ( int i = 1 ; i <= size ; i++ )
    {
        printf("%d\n", a[i]);
    }
    printf("\n");
    insertionSort(a);

    printf("Sorted array:\n");
    for ( int i = 1 ; i <= size ; i++ )
    {
        printf("%d\n", a[i]);
    }

    return 0;
}