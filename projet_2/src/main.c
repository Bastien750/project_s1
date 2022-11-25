// a) Créer les structure processus(name, execution_time, priority) et liste(processus, next)
// b) ajout_activite(processus) <= simple fonction pour ajouter un noeud à notre file
// c) step(noeud) <= vérifie qu'il y a bien une file suivante. Si c'est le cas, on exécute le processus en affichant son nom et sa durée. (Pour l'exécution on attend juste le temps correspondant à la durée de l'activité)
// d) run(file) <= exécute la fonction step() jusqu'à arriver au bout de la liste
// e) Ecrire la fonction main() <= qui de ce que je comprends trie notre file en mettant à la fin ceux qui mettent le plus de temps à s'exécuter

// main.c <= contient la fonction main

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "file.h"
#include "structure.h"
#include <stdbool.h>

void affichage(processus tab[], int size, int count) {
    printf("[%d]: ", count);
    for (int j = 0; j < size; j++) {
        printf("%lf ", tab[j]->time_exec);
    }
    printf("\n");
}


void TriBulle(processus tab[], int size, int count) {
    processus tmp ; bool test;
    //Tri
    while (test) {  
        test = false;
        for (int i=0; i<size-1; i++) {
            if (tab[i]->time_exec > tab[i+1]->time_exec) {
                test=true;
                tmp=tab[i+1];
                tab[i+1]=tab[i];
                tab[i]=tmp;
                count++;
                affichage(tab,size,count);
            }
        }
    }
}


int main(){
    int nbrProcess;
    printf("Entrez le nombre de processus que vous voulez inclure dans l'ordonnanceur : ");
    scanf("%d", &nbrProcess);
    processus tab[nbrProcess] ;
    for (int i = 0; i < nbrProcess; i++)
    {
        tab[i] = MALLOC(Proc);
    }
    for (int i = 0; i < nbrProcess; i++)
    {
        printf("Processus n°%d :\n", i);
        printf("Entrez le nom du processus : ");
        scanf("%s", tab[i]->nom);
        printf("Entrez le temps d'execution du processus : ");
        scanf("%lf", &tab[i]->time_exec);
        //tab[i]->time_exec = rand()%5;
        printf("Entrez la priorite du processus : ");
        scanf("%d", &tab[i]->order);
    }
    TriBulle(tab, nbrProcess, 0);
    //quickSort(tab, 0, nbrProcess-1, nbrProcess, 0);    
    File *ordonnanceur = initialisation(tab[0]);
    for (int i = 1; i < nbrProcess; i++)
    {
        ajout_activite(ordonnanceur, tab[i]);
    }
    run(ordonnanceur);
    
}


