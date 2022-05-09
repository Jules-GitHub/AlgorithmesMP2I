#include "stdlib.h"
#include "stdio.h"

typedef int contenu;

struct file_s {
    contenu* support;
    int capacite;
    int debut;
    int fin;
};

typedef struct file_s file;

file cree_pile(int capacite) {

    contenu* support = malloc(sizeof(contenu)*capacite);
    file file = {
        .support = support,
        .capacite = capacite,
        .debut = 0,
        .fin = 0
    };
    return file;

}

void enfile(file* file, contenu valeur) {

    file->support[file->fin] = valeur;
    file->fin = (file->fin+1)%file->capacite;

    if (file->debut == file->fin) {
        file->capacite *= 2;
        file->support = realloc(file->support, sizeof(contenu)*file->capacite);
    }

}

contenu defile(file* file) {

    contenu valeur = file->support[file->debut];
    file->debut = (file->debut + 1)%file->capacite;
    return valeur;

}

int main() {

    return EXIT_SUCCESS;

}