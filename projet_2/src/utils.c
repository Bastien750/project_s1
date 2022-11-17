// Contient les fonctions pour trier la file, la fonction step et la fonction run
#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include <unistd.h>

void step(File *ordonnanceur){
    if (ordonnanceur->premier != NULL)
    {
        processus Process_enCour = defiler(ordonnanceur);
        printf("Nom de l'activité en cour : %s\n", Process_enCour->nom);
        printf("duree : %lf\n", Process_enCour->time_exec);
        sleep(Process_enCour->time_exec);
    }
    else
    {
        printf("L'odonnanceur est vide.\n");
    }
}

void run(File *ordonnanceur){
    do
    {
        step(ordonnanceur);
    } while (ordonnanceur->premier != NULL);
    
}