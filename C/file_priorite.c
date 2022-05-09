#include "stdlib.h"
#include "stdio.h"

typedef int contenu;

struct file_prio_s {
    contenu* support;
    int capacite;
    int taille;
};

typedef struct file_prio_s file_prio;

void echanger(contenu* tableau, int i, int j) {
    contenu temp = tableau[i];
    tableau[i] = tableau[j];
    tableau[j] = temp;
}

void tamiser(contenu* tableau, int taille, int indice) {

    if (2*indice+1 < taille) {

        int indiceFils;
        if (2*indice+2 < taille && tableau[2*indice+2] > tableau[2*indice+1]) {
            indiceFils = 2*indice+2;
        } else {
            indiceFils = 2*indice+1;
        }
        if (tableau[indice] < tableau[indiceFils]) {
            echanger(tableau, indice, indiceFils);
        }
        tamiser(tableau, taille, indiceFils);
        
    }

}

file_prio cree_file_prio(int capacite) {

    contenu* support = malloc(sizeof(contenu)*capacite);
    file_prio f = {
        .support = support,
        .capacite = capacite,
        .taille = 0
    };
    return f;

}

void ajoute(file_prio* f, contenu valeur) {

    if (f->taille == f->capacite) {
        f->capacite *= 2;
        f->support = realloc(f->support, sizeof(contenu)*f->capacite);
    }
    f->support[f->taille] = valeur;
    f->taille++;

    int i = f->taille - 1;
    while (i > 0 && f->support[i] > f->support[(i - 1) / 2]){
        echanger(f->support, i, (i - 1) / 2);
        i = (i - 1) / 2;
    }

}

contenu retire_max(file_prio* f) {

    contenu max = f->support[0];
    f->support[0] = f->support[f->taille - 1];
    f->taille--;
    tamiser(f->support, f->taille, 0);
    return max;

}

int main() {

    file_prio f = cree_file_prio(32);

    ajoute(&f, 120);
    ajoute(&f, 600);
    ajoute(&f, 12000);
    ajoute(&f, 89);
    ajoute(&f, 45);
    ajoute(&f, 1000);
    ajoute(&f, 400);

    for (int i=0; i<7; i++) {
        printf("%d\n", retire_max(&f));
    }

    return EXIT_SUCCESS;

}