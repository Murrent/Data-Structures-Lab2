//
// Created by Martin on 2021-02-24.
//

#include "console.h"
#include <stdio.h>
#include <stdlib.h>

void plotArray(const int* array, int size) {
    for (int index = 0; index < size; ++index) {
        for (int number = 0; number < array[index]; ++number) {
            printf("%c", "#");
        }
        printf("\n");
    }
    //_sleep(1000);
    system("clear");
}

void plotList(List* list) {

}
