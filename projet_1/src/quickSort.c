#include <stdlib.h>
#include <stdio.h>
#include "structure.h"

/**
 * It prints the final_distance of each Logement in the array
 * 
 * @param logements an array of Logement pointers
 * @param size the number of logements
 */
void affichage(Logement * logements, int size) {
    for (int j = 0; j < size; j++) {
        printf("%lf ", logements[j]->final_distance);
    }
    printf("\n");
}

//Quick Sort

/**
 * It swaps the values of two elements in an array
 * 
 * @param t the array of Logement
 * @param i the index of the first element to swap
 * @param j the index of the first element of the subarray
 */
void swap(Logement *t, int i, int j) {
    Logement tmp;
    tmp = t[i];
    t[i] = t[j];
    t[j] = tmp;
}

/**
 * It takes an array of pointers to Logement structs, and sorts them by their final_distance member
 * 
 * @param logement_y an array of pointers to Logement structs
 * @param first the first index of the array
 * @param last the last index of the array
 * @param size the size of the array
 */
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
