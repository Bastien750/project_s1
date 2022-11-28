// a) Demander à l'utilisateur de remplir des données sur son logement. 
// Créer la structure logement qui contient tout les attributs du fichier CSV. 
// Créer la fonction qui lis dans le fichier CSV et créer un tableau dont la taille sera le nombre de logements du fichier. (Utiliser la fonction strtok(string, delimiter) inclus avec string.h)
// Ce tableau sera rempli d'une structure contenant la structure logement et un entier correspondant à la distance calculée (tab[i].logement && tab[i].distance) 
// Créer la fonction qui traduit la formule de calcul de distance avec en paramètre l'id du logement X et le tableau. 
// Stocker les résultats de la formule dans notre tableau. 

// b) Créer la fonction randomiser et trier

// c) Créer la fonction qui calcul la moyenne de prix des k logements les plus similaires. Exécuter la fonction avec plusieurs k (pour faire varier k comme dans l'énoncé). Stocker le prix trouvé qui sera le prix prédit.
// Stocker notre modèle dans le tableau excel (créer une fonction qui le fait)

// d) Exécuter le programme plusieurs fois

#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include "structure.h"
#include"utils.h"

int main(){
    Logement logement_x = MALLOC(Critere);
    int k;
    printf("Bonjour,\nBienvenu dans ce logiciel qui va vous permettre de trouver le prix de votre logement airBnb!\n");
    printf("Pouvez vous d'abord entrez le numero de votre logement :");
    scanf("%lf", &logement_x->id);
    printf("accomodates :");
    scanf("%lf", &logement_x->accomodates);
    printf("bedrooms :");
    scanf("%lf", &logement_x->bedrooms);
    printf("bathrooms :");
    scanf("%lf", &logement_x->bathrooms);
    printf("beds :");
    scanf("%lf", &logement_x->beds);
    printf("price :");
    scanf("%lf", &logement_x->price);
    printf("minimum_nights :");
    scanf("%lf", &logement_x->minimum_nights);
    printf("maximum_nights :");
    scanf("%lf", &logement_x->maximum_nights);
    printf("number_of_reviews :");
    scanf("%lf", &logement_x->number_of_reviews);
    int size=-1;
    count_line(&size);
    Logement logement_y[size];
    for (int i = 0; i < size; i++)
    {
        logement_y[i]=MALLOC(Critere);
    }
    init_logement_y(logement_y, size);
    formule_distance(logement_x, logement_y, size);
    //quickSort(logement_y, 0, size, size, 0);
    printf("Avec combien de logement voulez-vous comparer le votre :");
    scanf("%d", &k);
    logement_x->price=moyenne_prix(logement_y, k);
    ajout_logement_x(logement_x, size);

}