#ifndef structure
#define structure

#define MALLOC(x)(( x * ) malloc(sizeof(x)))

typedef struct Critere{
    double id; //0
    double accomodates; //1
    double bedrooms; //2
    double bathrooms; //3
    double beds; //4
    double price; //5
    double minimum_nights; //6
    double maximum_nights; //7
    double number_of_reviews; //8
    double distance[3]; //9
    double final_distance; //10
} Critere;

typedef Critere* Logement ;

#endif