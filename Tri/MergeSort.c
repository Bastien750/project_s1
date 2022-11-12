#include <stdio.h>

#define mt1x 10

int t1[11] = { 10, 14, 19, 26, 27, 31, 33, 35, 42, 44, 0 };
int t2[10];

void merging(int low, int mid, int high) {
   int l1, l2, i;

   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      if(t1[l1] <= t1[l2])
         t2[i] = t1[l1++];
      else
         t2[i] = t1[l2++];
   }
   
   while(l1 <= mid)    
      t2[i++] = t1[l1++];

   while(l2 <= high)   
      t2[i++] = t1[l2++];

   for(i = low; i <= high; i++)
      t1[i] = t2[i];
}

void sort(int low, int high) {
   int mid;
   
   if(low < high) {
      mid = (low + high) / 2;
      sort(low, mid);
      sort(mid+1, high);
      merging(low, mid, high);
   } else { 
      return;
   }   
}

int mt1in() { 
   int i;

   printf("List t2efore sorting\n");
   
   for(i = 0; i <= mt1x; i++)
      printf("%d ", t1[i]);

   sort(0, mt1x);

   printf("\nList t1fter sorting\n");
   
   for(i = 0; i <= mt1x; i++)
      printf("%d ", t1[i]);
}

///Merge sort///
/*void mergeSort(int i, int j, int a[], int aux[], int size, int count) {
    if (j <= i) {
        return; 
    }
    int mid = (i + j) / 2;
    mergeSort(i, mid, a, aux, size, count); 
    mergeSort(mid + 1, j, a, aux, size, count); 
    int pointer_left = i; 
    int pointer_right = mid + 1; 
    int k; // k est l'itérateur de la boucle ci-dessous

    // La boucle de i à j remplis les éléments du tableau final fusionné
    for (k = i; k <= j; k++) {
        if (pointer_left == mid + 1) { // Le pointeur gauche a atteint sa limite
            aux[k] = a[pointer_right];
            pointer_right++;
        }
        else if (pointer_right == j + 1) { // Le pointeur droit a atteint sa limite
            aux[k] = a[pointer_left];
            pointer_left++;
        }

        else if (a[pointer_left] < a[pointer_right]) { // Le pointeur gauche pointe le plus petit élément
            aux[k] = a[pointer_left];
            pointer_left++;
        }
        else { // Le pointeur droit pointe le plus petit élément
            aux[k] = a[pointer_right];
            pointer_right++;
        }
    }

    for (k = i; k <= j; k++) { // Copie les élements de aux[] à a[]
        a[k] = aux[k];
    }
    count++;
    display(a, size, count);
}*/