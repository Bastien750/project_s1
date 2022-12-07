#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include "structure.h"



/**
 * It takes a pointer to a Logement struct, and an integer, and then it shuffles the array of Logement
 * structs
 * 
 * @param logement_y is a pointer to a Logement structure
 * @param size the size of the array
 */
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

/**
 * It takes a logement_x and a logement_y array, and for each element of the logement_y array, it
 * calculates the distance between logement_x and logement_y[i] and stores it in
 * logement_y[i]->final_distance
 * 
 * @param logement_x the logement we want to compare to the others
 * @param logement_y an array of structs
 * @param size the number of elements in the array
 */
void formule_distance(Logement logement_x, Logement *logement_y, int size){
    for (int y = 0; y < size; y++)
    {        
        logement_y[y]->distance[0] = pow(logement_x->accomodates-logement_y[y]->accomodates, 2); //met chaque caractèristique au carré et les additionnes
        logement_y[y]->distance[1] = pow(logement_x->bedrooms-logement_y[y]->bedrooms, 2); //met chaque caractèristique au carré et les additionnes
        logement_y[y]->distance[2] = pow(logement_x->beds-logement_y[y]->beds, 2);
        logement_y[y]->final_distance = sqrt(logement_y[y]->distance[0]+logement_y[y]->distance[1]+logement_y[y]->distance[2]);
    }
}

/**
 * It calculates the average price of the kth logement.
 * 
 * @param logement_y the array of Logement structs
 * @param k the number of logements in the array
 */
double moyenne_prix(Logement *logement_y, int k){
    double price;
    for (int i = 0; i < k; i++)
    {
        price = price + logement_y[i]->price;
    }
    price=price/k;
    return price;
}


