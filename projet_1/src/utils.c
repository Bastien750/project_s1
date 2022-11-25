#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include"structure.h"

void count_line(int *nbrline){
    FILE* fichier = NULL;
 
    fichier = fopen("../data/airbnb_donnees_propre.csv", "r");  
    char ch;  
    if (fichier != NULL)
    {               
        while(!feof(fichier))
        {
            fscanf(fichier,"%s",&ch);
            *nbrline++;
        }
    }  
    fclose(fichier);  
}

void init_logement_y(double **logement_y){
    FILE* fichier = NULL;
 
    fichier = fopen("../data/airbnb_donnees_propre.csv", "r");    
    char* line[20];
    if (fichier != NULL)
    {               
        fgets(line, 20,fichier);   
            for (int y = 0; y < 7917; y++)
            { 
                logement_y[0][y] = atof(strtok(line, ",")); //strtok separe le char et atof le transforme en double
                for (int i = 1; i < 9; i++)
                { 
                    logement_y[i][y]= atof(strtok(NULL, ","));
                }
            }  
        }
        fclose(fichier);    
}

void formule_distance(double *logement_x, double **logement_y){
    double tmp;
    for (int y = 0; y < 7918; y++)
    {
        for (int i = 1; i < 9; i++)
        {
            tmp =tmp + pow(logement_x[i]-logement_y[i][y], 2); //met chaque caractèristique au carré et les additionnes
        }
        logement_y[10][y]= sqrt(tmp); // fait la racine de la somme
    }
}

