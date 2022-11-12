#include <stdlib.h>
#include <stdio.h>

void afficheTab(int* tab, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d | ", tab[i]) ;
    }
    printf("\n") ;
}

int BornesSup(int* tab, int n){
    int max =  tab[0];
    for (int i = 0; i < n; i++)
    {
            if (tab[i] > max)
            {
                max = tab[i] ;
            }
        }
    return max ;
}

int BornesInf(int* tab, int n){
    int min ;
    for (int i = 0; i < n; i++)
    {
            if (tab[i] < min)
            {
                min = tab[i] ;
            }
        }
    return min ;
}

void Remplissage(int* tab1,int* tab2, int n1, int min){
    int a ;
    for (int i = 0; i < n1; i++)
    {
        a = tab1[i] - min ;
        tab2[a]++ ;
    }
    
}

void recompose(int tab[], int tab2[], int s, int mine)
{
    int i, j;
    int start = 0;
    int end = 0;
    for(i=0; i<s; i++)
    {
        end = end + tab2[i];
        if(tab2[i] != 0)
        {
            for(j=start; j<end; j++)
            {
                tab[j] = i + mine;
            }
        }
        start = start + tab2[i];
    }
}

int main (){
    int tab1[13] = {4,0,-1,2,0,0,2,5,-1,2,0,4,2} ;
    afficheTab(tab1, 13) ;
    int max = BornesSup(tab1, 13) ;
    int min = BornesInf(tab1, 13) ;
    int m = max - min +1 ;
    int tab2[m] ;
    for (int i = 0; i < m; i++)
    {
        tab2[i] = 0 ;
    }
    afficheTab(tab2, m) ;
    Remplissage(tab1, tab2, 13, min) ;
    afficheTab(tab2, m) ;
    recompose(tab1, tab2, m, min) ;
    afficheTab(tab1, 13)

}
