#include "stdlib.h"
#include "stdio.h"

void echanger(int* tableau, int i, int j) {
    int temp = tableau[i];
    tableau[i] = tableau[j];
    tableau[j] = temp;
}

void tamiser(int* tableau, int taille, int indice) {

    if (2*indice+1 < taille) {

        int indiceFils;
        if (2*indice+2 < taille && tableau[2*indice+2] > tableau[2*indice+1]) {
            indiceFils = 2*indice+2;
        } else {
            indiceFils = 2*indice+1;
        }
        if (tableau[indice] < tableau[indiceFils]) {
            echanger(tableau, indice, indiceFils);
            tamiser(tableau, taille, indiceFils);
        }
        
    }

}

void tri_par_tas(int* tableau, int taille) {

    for (int i = taille/2 - 1; i>=0; i--) {
        tamiser(tableau, taille, i);
    }
    for (int i=taille-1; i>0; i--) {
        echanger(tableau, i, 0);
        tamiser(tableau, i, 0);
    }

}

int main() {

    int tab[] = {2, 5, 7, 8, 6, 3, 4, 1};

    tri_par_tas(tab, 8);

    printf("%d %d %d %d %d %d %d %d\n", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5], tab[6], tab[7]);

    return EXIT_SUCCESS;

}