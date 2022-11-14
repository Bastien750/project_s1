#ifndef structure
#define structure

typedef struct Proc{
    char nom;
    double time_exec;
    int order;
} Proc;

typedef Proc* processus ;

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