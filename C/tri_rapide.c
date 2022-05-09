#include "stdlib.h"
#include "stdio.h"

void echanger(int* tableau, int i, int j) {
    int temp = tableau[i];
    tableau[i] = tableau[j];
    tableau[j] = temp;
}

int partitionne(int* tableau, int taille) {

    int limite = 0;
    int pivot = tableau[limite];
    for (int i=1; i<taille; i++) {
        if (tableau[i] < pivot) {
            limite++;
            echanger(tableau, limite, i);
        }
    }
    echanger(tableau, limite, 0);
    return limite;

}

void tri_rapide(int* tableau, int taille) {

    int indicePivot = partitionne(tableau, taille);
    if (indicePivot > 0) {
        tri_rapide(tableau, indicePivot);
    }
    if (indicePivot < taille-1) {
        tri_rapide(&tableau[indicePivot+1], taille-(indicePivot+1));
    }

}

int main() {

    int tab[] = {2, 5, 7, 8, 6, 3, 4, 1};

    tri_rapide(tab, 8);

    printf("%d %d %d %d %d %d %d %d\n", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5], tab[6], tab[7]);

    return EXIT_SUCCESS;

}