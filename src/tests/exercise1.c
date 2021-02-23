//
// Created by Martin on 2021-02-23.
//

#include <stdio.h>

#include "../load_files/load_file.h"
#include "../insertion_sort/insertion_sort.h"

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
    insertion_sort(a);

    printf("Sorted array:\n");
    for ( int i = 1 ; i <= size ; i++ )
    {
        printf("%d\n", a[i]);
    }

    return 0;
}