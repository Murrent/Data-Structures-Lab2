// Martin Vickgren, Samson Tesfalem
//
// Created by Martin on 2021-02-24.
//

#include <stdio.h>

#include "../list/list.h"
#include "../load_files/load_file.h"
#include "../radix_sort/radix_sort.h"

/**
 * This program does the same as exercise2.c but is sorting the list in descending order.
 * @param argc
 * @param argv
 * @return
 */
int main( int argc, char* argv[] )
{
    List* list = createList();

    const char* fName = argv[1];

    int* a = load_file(fName);

    int size = a[0];
    printf("Input array:\n");
    for ( int i = 1 ; i <= size ; i++ )
    {
        printf("%d\n", a[i]);
        insert(list, createNode(a[i]));
    }
    printf("\n");

    radixSortDescending(list);

    printf("Sorted list:\n");
    printList(list);

    return 0;
}