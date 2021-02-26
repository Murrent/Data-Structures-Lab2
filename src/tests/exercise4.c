// Martin Vickgren, Samson Tesfalem
//
// Created by Martin on 2021-02-25.
//

#include <stdio.h>

#include "../list/list.h"
#include "../load_files/load_file.h"
#include "../radix_sort/radix_sort.h"
#include "../insertion_sort/insertion_sort.h"

/**
 * This program takes the filepath from argc[1], loads the file and adds it's content into an integer array and copy it
 * over to two lists of integers.
 * listA is sorted in ascending order and is displayed as a graph in the console each time an element is checked or
 * moved.
 * listB is sorted in descending order and also displayed the same way as listA.
 * The integer array is now sorted using insertion sort and displayed the same way as the lists.
 * @param argc
 * @param argv
 * @return
 */
int main( int argc, char* argv[] )
{
    List* listA = createList();
    List* listB = createList();

    const char* fName = argv[1];

    int* a = load_file(fName);

    int size = a[0];
    for ( int i = 1 ; i <= size ; i++ )
    {
        insert(listA, createNode(a[i]));
        insert(listB, createNode(a[i]));
    }

    radixSortPlotAscending(listA);
    radixSortPlotDescending(listB);

    insertionSortGraphed(a);

    return 0;
}