#ifndef utils
#define utils

void count_line(int *nbrline);
void init_logement_y(double **logement_y);
void formule_distance(double *logement_x, double **logement_y);
double moyenne_prix(double *logement_x, double **logement_y, int k);
void ajout_logement_x(double *logement_x, int size);

#endif