#ifndef structure
#define structure

typedef struct processus{
    char nom;
    double time_exec;
    int order;
} processus;

typedef processus* Proc ;

typedef struct Element Element;
struct Element
{
    processus process;
    Element *suivant;
};

typedef struct File File;
struct File
{
    Element *premier;
};

#endif