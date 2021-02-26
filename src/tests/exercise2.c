//
// Created by Martin on 2021-02-23.
//

#include <stdio.h>

#include "../list/list.h"
#include "../load_files/load_file.h"
#include "../radix_sort/radix_sort.h"

/**
 * This program takes the filepath from argc[1], loads the file and adds it's content into a list of integers.
 * The input is first printed and stored in the list. Then we use radix sort the ascending version.
 * And then the sorted list is printed.
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

    radixSortAscending(list);

    printf("Sorted list:\n");
    printList(list);

    return 0;
}