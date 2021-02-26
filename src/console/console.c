//
// Created by Martin on 2021-02-24.
//

#include "console.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void plotArray(const int* array, int size, int current) {
    system("cls");
    for (int index = 1; index < size; ++index) {
        for (int number = 0; number < array[index]; ++number) {
            printf("%c", '#');
        }
        if (index == current)
            printf(" <---");
        printf("\n");
    }
    usleep(200000); // Sleeping for 200000 microseconds
}

void plotList(List* list, Node* current) {
    system("cls");
    for (Node* node = list->head; node; node = node->next) {
        for (int number = 0; number < node->key; ++number) {
            printf("%c", '#');
        }
        if (node == current)
            printf(" <---");
        printf("\n");
    }
    usleep(200000); // Sleeping for 200000 microseconds
}
