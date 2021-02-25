//
// Created by Martin on 2021-02-24.
//

#include "radix_sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../console/console.h"

int getMax(List* list) {
    Node* max = list->head;
    for (Node* tmp = list->head->next; tmp; tmp = tmp->next) {
        if (tmp->key > max->key)
            max = tmp;
    }
    return max->key;
}

void countSortAscending(List* list, int exponent) {
    int i = 0;
    Node* tmp = NULL;

    int* sortedArray = (int*)malloc(list->length * sizeof(int));
    memset(sortedArray, 0, list->length * sizeof(int));

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

void radixSortAscending(List* list) {
    int max = getMax(list);

    for (int exponent = 1; max / exponent > 0; exponent *= 10){
        countSortAscending(list, exponent);
    }
}

void countSortDescending(List* list, int exponent) {
    int i = 0;
    Node* tmp = NULL;

    int* sortedArray = (int*)malloc(list->length * sizeof(int)); // Temporary array for the sorted array
    memset(sortedArray, 0, list->length * sizeof(int)); //Setting values to 0

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

void radixSortDescending(List* list) {
    int max = getMax(list);

    for (int exponent = 1; max / exponent > 0; exponent *= 10){
        countSortDescending(list, exponent);
    }
}

void countSortPlotAscending(List* list, int exponent) {
    int i = 0;
    Node* tmp = NULL;

    int* sortedArray = (int*)malloc(list->length * sizeof(int));
    memset(sortedArray, 0, list->length * sizeof(int));

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

    int* sortedArray = (int*)malloc(list->length * sizeof(int)); // Temporary array for the sorted array
    memset(sortedArray, 0, list->length * sizeof(int)); //Setting values to 0

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