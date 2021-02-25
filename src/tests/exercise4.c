//
// Created by Martin on 2021-02-25.
//

#include <stdio.h>

#include "../list/list.h"
#include "../load_files/load_file.h"
#include "../radix_sort/radix_sort.h"
#include "../insertion_sort/insertion_sort.h"

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

    radixSortAscending(listA);
    radixSortDescending(listB);

    insertion_sort_graphed(a);

    return 0;
}