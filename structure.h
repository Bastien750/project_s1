#ifndef structure
#define structure

#define MALLOC(x)(( x * ) malloc(sizeof(x)))

typedef struct Critere{
    double id;
    double accomodates;
    double bedrooms;
    double bathrooms;
    double beds;
    double price;
    double minimum_nights;
    double maximum_nights;
    double number_of_reviews;
    double distance[3];
    double final_distance;
} Critere;

typedef Critere* Logement ;

#endif