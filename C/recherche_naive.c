#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "stdbool.h"

int recherche_naive(char* texte, char* mot) {

    int longueur = strlen(texte);
    int taille = strlen(mot);

    for (int i=0; i<longueur-taille; i++) {

        bool occurrence = true;
        int j = 0;
        while (j<taille && occurrence) {
            if (texte[i+j] == mot[j]) {
                j++;
            } else {
                occurrence = false;
            }
        }
        if (occurrence) {
            return i;
        }

    }
    return -1;

}

int main() {

    char texte[] = "Bonjour je suis un texte dans lequel je vais faire une recherche";
    char mot[] = "dans";

    printf("%d\n", recherche_naive(texte, mot));

    return EXIT_SUCCESS;

}