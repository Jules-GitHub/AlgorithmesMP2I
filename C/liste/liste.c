#include "stdlib.h"
#include "stdio.h"
#include "liste.h"

liste cree_liste(int capacite) {
    contenu* support = malloc(sizeof(contenu)*capacite);
    liste liste = {
        .support = support,
        .capacite = capacite,
        .taille = 0
    };
    return liste;
}

void ajoute(liste* liste, contenu valeur) {
    if (liste->taille == liste->capacite) {
        liste->capacite *= 2;
        liste->support = realloc(liste->support, sizeof(contenu)*liste->capacite);
    }
    liste->support[liste->taille] = valeur;
    liste->taille++;
}

liste concatene(liste* liste1, liste* liste2) {
    liste liste3 = cree_liste(liste1->taille + liste2->taille);
    for (int i=0; i<liste1->taille; i++) {
        ajoute(&liste3, liste1->support[i]);
    }
    for (int i=0; i<liste2->taille; i++) {
        ajoute(&liste3, liste2->support[i]);
    }
    return liste3;
}

int main() {

    return EXIT_SUCCESS;

}