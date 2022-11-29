// Contient les fonctions pour trier la file, la fonction step et la fonction run
#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include <unistd.h>

/**
 * It takes a pointer to a File structure, and if the File is not empty, it takes the first processus
 * in the File, prints its name and its execution time, and then sleeps for the execution time
 * 
 * @param ordonnanceur the queue
 */
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

/**
 * It runs the scheduler until there are no more processes to run
 * 
 * @param ordonnanceur the queue of processes
 */
void run(File *ordonnanceur){
    while (ordonnanceur->premier != NULL)
    {
        step(ordonnanceur);
    } 
    
}