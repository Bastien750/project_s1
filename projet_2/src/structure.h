#ifndef structure
#define structure

#define MALLOC(x)(( x * ) malloc(sizeof(x)))

typedef struct Proc{
    char nom[20];
    double time_exec;
    int order;
} Proc;

typedef Proc* processus ;

typedef struct Element Element;
struct Element
{
    processus process ;
    Element *suivant;
};

typedef struct File File;
struct File
{
    Element *premier;
};

#endif