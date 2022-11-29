#include <stdlib.h>
#include <stdio.h>
#include "structure.h"

void affichage(Logement * logements, int size) {
    for (int j = 0; j < size; j++) {
        printf("%lf ", logements[j]->final_distance);
    }
    printf("\n");
}

//Quick Sort

void swap(Logement *t, int i, int j) {
    Logement tmp;
    tmp = t[i];
    t[i] = t[j];
    t[j] = tmp;
}

void quickSort(Logement * logement_y, int first, int last, int size) {
    int i, j, pivot;
    if (first < last) {
        pivot = first;
        i = first;
        j = last;
        while (i < j) {
            while (logement_y[i]->final_distance <= logement_y[pivot]->final_distance && i < last) i++;
            while (logement_y[j]->final_distance > logement_y[pivot]->final_distance) j--;
            if (i < j) {
                swap(logement_y, i, j);
            }
        }
        swap(logement_y, pivot, j) ;
        quickSort(logement_y, first, j - 1, size);
        quickSort(logement_y, j + 1, last, size);
    }
}
