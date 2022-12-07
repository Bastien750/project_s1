#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include "structure.h"

void count_line(int *nbrline){
    FILE* fichier = NULL;
    fichier = fopen("../data/airbnb_donnees_propre.csv", "r"); 
    
    char *ch = malloc(100*sizeof(char)) ;
    if (fichier != NULL)
    {               
        while(!feof(fichier))
        {
            fgets(ch,100,fichier);
            *nbrline = *nbrline +1;
        }
    }  
    
    fclose(fichier);  
}

void init_logement_y(Logement *logement_y, int size){
    FILE* fichier = NULL;
 
    fichier = fopen("../data/airbnb_donnees_propre.csv", "r");    
    char line[100];
    if (fichier != NULL)
    {               
        fgets(line, 100,fichier); 
            for (int y = 0; y < size-1; y++)
            { 
                fgets(line, 100,fichier); 
                logement_y[y]->id = atof(strtok(line, ",")); //strtok separe le char et atof le transforme en double
                logement_y[y]->bedrooms= atof(strtok(NULL, ","));
                logement_y[y]->bathrooms= atof(strtok(NULL, ","));
                logement_y[y]->beds= atof(strtok(NULL, ","));
                logement_y[y]->price= atof(strtok(NULL, ","));
                logement_y[y]->minimum_nights= atof(strtok(NULL, ","));
                logement_y[y]->maximum_nights= atof(strtok(NULL, ","));
                logement_y[y]->number_of_reviews= atof(strtok(NULL, ","));

            }  
        }
        fclose(fichier);    
}

void ajout_logement_x(Logement logement_x, int size){
    FILE* fichier = NULL;
    fichier = fopen("../data/airbnb_donnees_propre.csv", "r+");   
    char *ch = malloc(sizeof(char));  
    if (fichier != NULL)
    {     
        while(!feof(fichier))
        {
            fgets(ch,20,fichier);
        }
        fprintf(fichier,"%.0lf,%.0lf,%.1lf,%.1lf,%.1lf,%.1lf,%.0lf,%.0lf,%.0lf\n",logement_x->id, logement_x->accomodates, logement_x->bedrooms, logement_x->bathrooms, logement_x->beds, logement_x->price, logement_x->minimum_nights, logement_x->maximum_nights, logement_x->number_of_reviews);
    }  
    fclose(fichier); 
}
