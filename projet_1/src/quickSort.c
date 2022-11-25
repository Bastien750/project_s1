#include <stdlib.h>
#include <stdio.h>

void affichage(int tab[], int size, int count) {
    printf("[%d]: ", count);
    for (int j = 0; j < size; j++) {
        printf("%d ", tab[j]);
    }
    printf("\n");
}

//Quick Sort

void swap(double **t, int i, int j) {
    int tmp;
    tmp = t[i];
    t[i] = t[j];
    t[j] = tmp;
}

void quickSort(double **logement_y, int first, int last, int size, int count) {
    int i, j, pivot, tmp;
    if (first < last) {
        pivot = first;
        i = first;
        j = last;
        while (i < j) {
            while (logement_y[i] <= logement_y[pivot] && i < last) i++;
            while (logement_y[j] > logement_y[pivot]) j--;
            if (i < j) {
                swap(logement_y, i, j);
            }
            count++;
            affichage(logement_y, size, count);
        }
        swap(logement_y, pivot, j) ;
        quickSort(logement_y, first, j - 1, size, count);
        quickSort(logement_y, j + 1, last, size, count);
    }
}
