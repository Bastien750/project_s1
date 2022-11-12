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

void swap(int* t, int i, int j) {
    int tmp;
    tmp = t[i];
    t[i] = t[j];
    t[j] = tmp;
}

void quickSort(int t[], int first, int last, int size, int count) {
    int i, j, pivot, tmp;
    if (first < last) {
        pivot = first;
        i = first;
        j = last;
        while (i < j) {
            while (t[i] <= t[pivot] && i < last) i++;
            while (t[j] > t[pivot]) j--;
            if (i < j) {
                swap(t, i, j);
            }
            count++;
            affichage(t, size, count);
        }
        swap(t, pivot, j) ;
        quickSort(t, first, j - 1, size, count);
        quickSort(t, j + 1, last, size, count);
    }
}




int main(int argc, char** argv) {
    int t[8] = { 27,63,1,72,64,58,14,9 };
    int size = 8;
  printf("-------- QUICKSORT --------\n");
    quickSort(t, 0, size - 1, size, 0);
}