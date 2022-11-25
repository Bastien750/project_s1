#ifndef file
#define file
#include "structure.h"

File *initialisation(processus nvProc);
void ajout_activite(File *ordonnanceur, processus nvProcess);
processus defiler(File *ordonnanceur);

#endif