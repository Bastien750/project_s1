// Contient les fonctions pour créer un processus, créer une file et créer un noeud ainsi que les structures processus et file
#include <stdio.h>
#include <stdlib.h>
#include "structure.h"

/**
 * It creates a new file and adds the new process to it
 * 
 * @param nvProc the process to add to the queue
 * 
 * @return A pointer to a File structure.
 */
File *initialisation(processus nvProc)
{
    File *file = MALLOC(File);
    Element *element = MALLOC(Element);
    element->process = nvProc;
    element->suivant = NULL;
    file->premier = element;
    return file;
}

/**
 * It adds a new process to the end of the queue
 * 
 * @param ordonnanceur the queue
 * @param nvProcess the process to add to the queue
 */
void ajout_activite(File *ordonnanceur, processus nvProcess)
{
    Element *nouveau = malloc(sizeof(*nouveau));
    if (ordonnanceur == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveau->process = nvProcess;
    nouveau->suivant = NULL;

    if (ordonnanceur->premier != NULL) /* La file n'est pas vide */
    {
        /* On se positionne à la fin de la file */
        Element *elementActuel = ordonnanceur->premier;
        while (elementActuel->suivant != NULL)
        {
            elementActuel = elementActuel->suivant;
        }
        elementActuel->suivant = nouveau;
    }
    else /* La file est vide, notre élément est le premier */
    {
        ordonnanceur->premier = nouveau;
    }
}

/**
 * It takes a pointer to a queue, checks if the queue is empty, if not, it takes the first element of
 * the queue, puts it in a variable, and then frees the first element of the queue
 * 
 * @param ordonnanceur the queue
 * 
 * @return A processus struct.
 */
processus defiler(File *ordonnanceur)
{
    if (ordonnanceur == NULL)
    {
        exit(EXIT_FAILURE);
    }

    processus ProcessDefile;

    /* On vérifie s'il y a quelque chose à défiler */
    if (ordonnanceur->premier != NULL)
    {
        Element *elementDefile = ordonnanceur->premier;

        ProcessDefile = elementDefile->process;
        ordonnanceur->premier = elementDefile->suivant;
        free(elementDefile);
    }

    return ProcessDefile;
}