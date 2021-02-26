// Martin Vickgren, Samson Tesfalem
//
// Created by Martin on 2021-02-25.
//

#include <stdio.h>

#include "../list/list.h"
#include "../radix_sort/radix_sort.h"
#include "../insertion_sort/insertion_sort.h"

/**
 * This program is testing our implementation of insertion sort and radix sort (LSD).
 * Radix sort (LSD) is tested using the lists from lab 1, listA is sorted in ascending order
 * and listB is sorted in descending order.
 * Insertion sort is tested using our personal numbers.
 * @return
 */
int main()
{
    List *listA = createList();
    List *listB = createList();

    insert(listA, createNode(3));
    insert(listA, createNode(1));
    insert(listA, createNode(5));
    insert(listA, createNode(10));
    insert(listA, createNode(8));
    insert(listA, createNode(7));

    insert(listB, createNode(5));
    insert(listB, createNode(2));
    insert(listB, createNode(9));
    insert(listB, createNode(6));
    insert(listB, createNode(1));
    insert(listB, createNode(2));

    int arrayA[9] = { 8, 2, 0, 0, 1, 0, 6, 0, 8 };
    int arrayB[9] = { 8, 2, 0, 0, 0, 0, 2, 2, 2 };

    radixSortAscending(listA);
    radixSortDescending(listB);

    insertionSort(arrayA);
    insertionSort(arrayB);

    for (Node* tmp = listA->head; tmp; tmp = tmp->next)
        printf("listA: %d\n", tmp->key);

    printf("\n");

    for (Node* tmp = listB->head; tmp; tmp = tmp->next)
        printf("listB: %d\n", tmp->key);

    printf("\n");

    for (int i = 1; i < arrayA[0]; ++i)
        printf("arrayA: %d\n", arrayA[i]);

    printf("\n");

    for (int i = 1; i < arrayB[0]; ++i)
        printf("arrayB: %d\n", arrayB[i]);

    return 0;
}