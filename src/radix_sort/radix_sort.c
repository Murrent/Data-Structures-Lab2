//
// Created by Martin on 2021-02-24.
//

#include "radix_sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../console/console.h"

/**
 * Creates and array of integers with the size of length and sets all values to 0.
 * @param length - size of array.
 * @return - the created int array.
 */
int *getIntArray(int length) {
    int* sortedArray = (int*)malloc(length * sizeof(int)); // Temporary array for the sorted array
    memset(sortedArray, 0, length * sizeof(int)); //Setting values to 0

    return sortedArray;
}

/**
 * Loops through the list and returns the key of the maximum value.
 * @param list
 * @return - The maximum key in the list.
 */
int getMax(List* list) {
    Node* max = list->head;
    for (Node* tmp = list->head->next; tmp; tmp = tmp->next) {
        if (tmp->key > max->key)
            max = tmp;
    }
    return max->key;
}

/**
 * This functions sorts the list by the exponent in ascending order. This means if there are "n" exponents in the
 * maximum value of list, this function needs to run "n" number of times for each exponent.
 * @param list
 * @param exponent
 */
void countSortAscending(List* list, int exponent) {
    int i = 0;
    Node* tmp = NULL;

    int *sortedArray = getIntArray(list->length);

    int count[10] = { 0 };

    for (tmp = list->head; tmp; tmp = tmp->next)
        count[(tmp->key / exponent) % 10]++;

    for (i = 1; i < 10; ++i)
        count[i] += count[i - 1];

    for (tmp = list->tail; tmp; tmp = tmp->previous) {
        int tmpIndex = (tmp->key / exponent) % 10;
        sortedArray[count[tmpIndex] - 1] = tmp->key;
        count[tmpIndex]--;
    }

    i = 0;
    for (tmp = list->head; tmp && i < list->length;) {
        tmp->key = sortedArray[i];
        tmp = tmp->next;
        i++;
    }
    free(sortedArray);
}
/**
 * This function finds the maximum element in the list and loops through the amount of exponents there are in it.
 * countSortAscending is called for every exponent in the maximum value of list.
 * @param list
 */
void radixSortAscending(List* list) {
    int max = getMax(list);

    for (int exponent = 1; max / exponent > 0; exponent *= 10){
        countSortAscending(list, exponent);
    }
}
/**
 * This function does the same as countSortAscending but sorts it in descending order.
 * @param list
 * @param exponent
 */
void countSortDescending(List* list, int exponent) {
    int i = 0;
    Node* tmp = NULL;

    int *sortedArray = getIntArray(list->length);

    int count[10] = { 0 };

    for (tmp = list->head; tmp; tmp = tmp->next)
        count[(tmp->key / exponent) % 10]++;

    for (i = 8; i >= 0; --i) //Looping from top-1 to bottom
        count[i] += count[i + 1]; //Adding the value of the element above

    for (tmp = list->tail; tmp; tmp = tmp->previous) {
        int tmpIndex = (tmp->key / exponent) % 10;
        sortedArray[count[tmpIndex] - 1] = tmp->key;
        count[tmpIndex]--;
    }

    i = 0;
    for (tmp = list->head; tmp && i < list->length;) {
        tmp->key = sortedArray[i];
        tmp = tmp->next;
        i++;
    }
    free(sortedArray);
}
/**
 * This function remains the same as radixSortAscending, all we need to do is call the countSortDescending function
 * instead.
 * @param list
 */
void radixSortDescending(List* list) {
    int max = getMax(list);

    for (int exponent = 1; max / exponent > 0; exponent *= 10){
        countSortDescending(list, exponent);
    }
}

/**
 * The functions below are the same radix function and count sorts but the also plot a graph of the list.
 */

void countSortPlotAscending(List* list, int exponent) {
    int i = 0;
    Node* tmp = NULL;

    int *sortedArray = getIntArray(list->length);

    int count[10] = { 0 };

    for (tmp = list->head; tmp; tmp = tmp->next){
        count[(tmp->key / exponent) % 10]++;
        plotList(list, tmp);
    }

    for (i = 1; i < 10; ++i)
        count[i] += count[i - 1];

    for (tmp = list->tail; tmp; tmp = tmp->previous) {
        int tmpIndex = (tmp->key / exponent) % 10;
        sortedArray[count[tmpIndex] - 1] = tmp->key;
        count[tmpIndex]--;
        plotList(list, tmp);
    }

    i = 0;
    for (tmp = list->head; tmp && i < list->length;) {
        tmp->key = sortedArray[i];
        tmp = tmp->next;
        i++;
        plotList(list, tmp);
    }
    free(sortedArray);
}

void radixSortPlotAscending(List* list) {
    int max = getMax(list);

    for (int exponent = 1; max / exponent > 0; exponent *= 10){
        plotList(list, NULL);
        countSortPlotAscending(list, exponent);
    }
    plotList(list, NULL);
}

void countSortPlotDescending(List* list, int exponent) {
    int i = 0;
    Node* tmp = NULL;

    int *sortedArray = getIntArray(list->length);

    int count[10] = { 0 };

    for (tmp = list->head; tmp; tmp = tmp->next) {
        count[(tmp->key / exponent) % 10]++;
        plotList(list, tmp);
    }

    for (i = 8; i >= 0; --i) //Looping from top-1 to bottom
        count[i] += count[i + 1]; //Adding the value of the element above

    for (tmp = list->tail; tmp; tmp = tmp->previous) {
        int tmpIndex = (tmp->key / exponent) % 10;
        sortedArray[count[tmpIndex] - 1] = tmp->key;
        count[tmpIndex]--;
        plotList(list, tmp);
    }

    i = 0;
    for (tmp = list->head; tmp && i < list->length;) {
        tmp->key = sortedArray[i];
        tmp = tmp->next;
        i++;
        plotList(list, tmp);
    }
    free(sortedArray);
}



void radixSortPlotDescending(List* list) {
    int max = getMax(list);

    for (int exponent = 1; max / exponent > 0; exponent *= 10){
        plotList(list, NULL);
        countSortPlotDescending(list, exponent);
    }
    plotList(list, NULL);
}