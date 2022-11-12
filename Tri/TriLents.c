#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void affichage(int tab[], int size, int count) {
    printf("[%d]: ", count);
    for (int j=0; j<size; j++) {
      printf("%d ", tab[j]);
    }
    printf("\n");
}

//Tri par selection
void TriSelec(int tab[], int size, int count) {
    int tmp;
    count++;
    affichage(tab,size,count);
    //Tri
    for (int i=0; i<size-1; i++) {
        if (tab[i] > tab[i+1]) {
            tmp=tab[i+1];
            tab[i+1]=tab[i];
            tab[i]=tmp;
            TriSelec(tab,size,count); 
        }
    }
}

//Tri à bulle (tri a sélection non récursif -> while)
void TriBulle(int tab[], int size, int count) {
    int tmp = 0; bool test;
    //Tri
    while (test) {  
        test = false;
        for (int i=0; i<size-1; i++) {
            if (tab[i] > tab[i+1]) {
                test=true;
                tmp=tab[i+1];
                tab[i+1]=tab[i];
                tab[i]=tmp;
                count++;
                affichage(tab,size,count);
            }
        }
    }
}

//Tri par insertion
void TriInser(int tab[], int size, int count) {
    int i, j, tmp;
    //Tri
    for (i = 1; i < size; i++) {
        count++;
        tmp= tab[i];
        j = i - 1;
        while (j > -1 && tab[j] > tmp) {
            tab[j + 1] = tab[j];
            j--;
        }
        tab[j + 1] = tmp;
        affichage(tab,size,count);
    }
}

int main(void) {
    int s=5;
    int a[5] = {61,88,10,23,51};
    //Tri par sélection
    printf("TRI PAR SELECTION \n");
    TriSelec(a,s,0);
    printf("\n");
    int b[5] = {61,88,10,23,51};
    // Tri à bulle
    printf("TRI A BULLE \n");
    TriBulle(b,s,0);
    printf("\n");
    int c[5] = {61,88,10,23,51};
    // Tri à insertion
    printf("TRI A INSERTION \n");
    TriInser(c,s,0);
    printf("\n");
    return 0;
}

