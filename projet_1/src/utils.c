#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include "structure.h"



void random_tab(Logement *logement_y, int size){
    srand(time(NULL));
    int nbr;
    Logement tmp = MALLOC(Critere);    
    for (int i = 0; i < size; i++)
    {
        nbr = rand()%size;
        tmp=logement_y[nbr];
        logement_y[nbr]=logement_y[i];
        logement_y[i]=tmp;
    }
}

void formule_distance(Logement logement_x, Logement *logement_y, int size){
    for (int y = 0; y < size; y++)
    {        
        logement_y[y]->distance[0] = pow(logement_x->accomodates-logement_y[y]->accomodates, 2); //met chaque caractèristique au carré et les additionnes
        logement_y[y]->distance[1] = pow(logement_x->bedrooms-logement_y[y]->bedrooms, 2); //met chaque caractèristique au carré et les additionnes
        logement_y[y]->distance[2] = pow(logement_x->beds-logement_y[y]->beds, 2);
        logement_y[y]->final_distance = sqrt(logement_y[y]->distance[0]+logement_y[y]->distance[1]+logement_y[y]->distance[2]);
    }
}

double moyenne_prix(Logement *logement_y, int k){
    double price;
    for (int i = 0; i < k; i++)
    {
        price = price + logement_y[i]->price;
    }
    price=price/k;
    return price;
}


