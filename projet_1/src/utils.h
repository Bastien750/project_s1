#ifndef utils
#define utils
#include "structure.h"

void random_tab(Logement *logement_y, int size);
void formule_distance(Logement logement_x, Logement *logement_y, int size);
double moyenne_prix(Logement *logement_y, int k);

#endif