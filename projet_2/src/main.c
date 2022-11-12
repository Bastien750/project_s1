// a) Créer les structure processus(name, execution_time, priority) et liste(processus, next)
// b) ajout_activite(processus) <= simple fonction pour ajouter un noeud à notre file
// c) step(noeud) <= vérifie qu'il y a bien une file suivante. Si c'est le cas, on exécute le processus en affichant son nom et sa durée. (Pour l'exécution on attend juste le temps correspondant à la durée de l'activité)
// d) run(file) <= exécute la fonction step() jusqu'à arriver au bout de la liste
// e) Ecrire la fonction main() <= qui de ce que je comprends trie notre file en mettant à la fin ceux qui mettent le plus de temps à s'exécuter

// main.c <= contient la fonction main

#include <stdio.h>
#include <stdlib.h>
#include <structure.h>
