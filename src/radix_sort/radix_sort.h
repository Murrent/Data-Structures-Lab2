//
// Created by Martin on 2021-02-24.
//

#ifndef LAB2SM_CLION_RADIX_SORT_H
#define LAB2SM_CLION_RADIX_SORT_H

#include "../list/list.h"

int getMax(List* list);
void countSortAscending(List* list, int exponent);
void radixSortAscending(List* list);
void countSortDescending(List* list, int exponent);
void radixSortDescending(List* list);

#endif //LAB2SM_CLION_RADIX_SORT_H
