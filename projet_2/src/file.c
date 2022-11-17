// Contient les fonctions pour créer un processus, créer une file et créer un noeud ainsi que les structures processus et file
#include <stdio.h>
#include <stdlib.h>
#include "structure.h"

File *initialisation()
{
    File *file = malloc(sizeof(*file));
    Element *element = malloc(sizeof(*element));
    //element->process = malloc(sizeof(processus));
    element->suivant = NULL;
    file->premier = element;
    return file;
}

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