#include "stdlib.h"
#include "stdio.h"

void tri_par_insertion(int* tableau, int taille) {

    for (int i=1; i<taille; i++) {

        int x = tableau[i];
        int j = i;
        while (j>0 && tableau[j-1] > x) {
            tableau[j] = tableau[j-1];
            j--;
        }
        tableau[j] = x;

    }

}

int main() {

    int tab[] = {2, 5, 7, 8, 6, 3, 4, 1};

    tri_par_insertion(tab, 8);

    printf("%d %d %d %d %d %d %d %d\n", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5], tab[6], tab[7]);

    return EXIT_SUCCESS;

}