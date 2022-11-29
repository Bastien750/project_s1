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
    int i, j, pivot, tmp;
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

int main(){
    Logement logements[10];
    for (int i = 0; i < 10; i++)
    {
        logements[i]=MALLOC(Critere);
    }    
    int tab[9];
    tab[0] = 7;
    tab[1] = 10;
    tab[2] = 3;
    tab[3] = 78;
    tab[4] = 9;
    tab[5] = 2;
    tab[6] = 11;
    tab[7] = 90;
    tab[8] = 13;
    for(int i=0; i<9; i++){
        logements[i]->id=i;
        logements[i]->accomodates=10;
        logements[i]->bedrooms=15;
        logements[i]->bathrooms=20;
        logements[i]->beds=2;
        logements[i]->price=150;
        logements[i]->maximum_nights=14;
        logements[i]->minimum_nights=7;
        logements[i]->number_of_reviews=12;
        logements[i]->distance[0] = 1;
        logements[i]->distance[1] = 2;
        logements[i]->distance[2] = 3;
        logements[i]->final_distance = tab[i];
    }
    quickSort(logements, 0 , 8, 9);
    affichage(logements, 9);
    return 0;
}