//
// Created by Namn on 2021-02-23.
//

#include "Unknown_sort.h"
#include <stdio.h>

 void load(List* list, int argc, char* argv[])
{
    const char* fName = argv[1];

    int* a = load_file(fName);

    int size = a[0];
    for ( int i = 1 ; i <= size ; i++ ) // note this loops from 1 <= i <= size
    {
        insert(List* list,a[i]);
    }
}


