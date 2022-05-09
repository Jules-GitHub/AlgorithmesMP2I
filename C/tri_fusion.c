#include "stdlib.h"
#include "stdio.h"

int* fusion(int* tab1, int* tab2, int n1, int n2) {

    int* tableau = malloc(sizeof(int)*(n1+n2));
    int i1 = 0;
    int i2 = 0;
    for (int i=0; i<(n1+n2); i++) {
        if (i1<n1 && i2<n2) {
            if (tab1[i1] < tab2[i2]) {
                tableau[i] = tab1[i1];
                i1++;
            } else {
                tableau[i] = tab2[i2];
                i2++;
            }
        } else if (i1<n1) {
            tableau[i] = tab1[i1];
            i1++;
        } else {
            tableau[i] = tab2[i2];
            i2++;
        }
    }
    return tableau;

}

void tri_fusion(int* tableau, int taille) {

    if (taille>1) {
        int milieu = taille/2;
        int* tab1 = tableau;
        int* tab2 = &tableau[milieu];

        tri_fusion(tab1, milieu);
        tri_fusion(tab2, taille-milieu);

        int* temp = fusion(tab1, tab2, milieu, taille-milieu);
        for (int i=0; i<taille; i++) {
            tableau[i] = temp[i];
        }
        free(temp);
    }

}

int main() {

    int tab[] = {2, 5, 7, 8, 6, 3, 4, 1};

    tri_fusion(tab, 8);

    printf("%d %d %d %d %d %d %d %d\n", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5], tab[6], tab[7]);

    return EXIT_SUCCESS;

}