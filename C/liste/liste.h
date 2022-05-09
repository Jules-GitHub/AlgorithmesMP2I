#include "stdlib.h"
#include "stdio.h"

typedef int contenu;

struct liste_s {
    contenu* support;
    int capacite;
    int taille;
};

typedef struct liste_s liste;

liste cree_liste(int capacite);

void ajoute(liste* liste, contenu valeur);

liste concatene(liste* liste1, liste* liste2);