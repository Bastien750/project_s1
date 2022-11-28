#ifndef utils
#define utils
#include "structure.h"


void count_line(int *nbrline);
void init_logement_y(Logement *logement_y, int size);
void formule_distance(Logement logement_x, Logement *logement_y, int size);
double moyenne_prix(Logement *logement_y, int k);
void ajout_logement_x(Logement logement_x, int size);

#endif