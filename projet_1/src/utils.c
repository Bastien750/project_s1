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

void init_logement_y(double **logement_y, int size){
    FILE* fichier = NULL;
 
    fichier = fopen("../data/airbnb_donnees_propre.csv", "r");    
    char* line[20];
    if (fichier != NULL)
    {               
        fgets(line, 20,fichier);   
            for (int y = 0; y < size-1; y++)
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

void formule_distance(double *logement_x, double **logement_y, int size){
    double tmp=0;
    for (int y = 0; y < size; y++)
    {
        for (int i = 1; i < 9; i++)
        {
            tmp =tmp + pow(logement_x[i]-logement_y[i][y], 2); //met chaque caractèristique au carré et les additionnes
        }
        logement_y[9][y]= sqrt(tmp); // fait la racine de la somme
    }
}

double moyenne_prix(double *logement_x, double **logement_y, int k){
    double price;
    for (int i = 0; i < k; i++)
    {
        price = price + logement_y[5][i];
    }
    price=price/k;
    return price;
}

void ajout_logement_x(double *logement_x, int size){
    FILE* fichier = NULL;
 
    fichier = fopen("../data/airbnb_donnees_propre.csv", "r+");  
    char ch;  
    if (fichier != NULL)
    {               
        while(!feof(fichier))
        {
            fscanf(fichier,"%s",&ch);
        }
        fprintf(fichier,"%d,%d,%d,%d,%d,%d,%d,%d,%d\n",logement_x[0], logement_x[1], logement_x[2], logement_x[3], logement_x[4], logement_x[5], logement_x[6], logement_x[7], logement_x[8]);
    }  
    fclose(fichier); 
}

