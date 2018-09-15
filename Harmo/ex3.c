// 1- [ ](Fonction)Remplissage d'un tableau de caractères => [a-z]U[A-Z]U[0-9] => Aléatoire
//    demander un param de taille du tableau < Max(20)
// 2- [ ](Fonction)Afficher
// 3- (Fonction) Rendre le nb de miniscules/maj/chiffres
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonctionsEx3.h"
#include "randfill.h"
#include <ctype.h>
#define MAX 20
int main()
{
    int tailleTableau, nb_min = 0, nb_maj = 0, nb_chi = 0;
    char T[MAX];
    do
    {
        printf("taille du tableau : ");
        scanf("%d", &tailleTableau);
    } while (tailleTableau >= MAX);

    remplir_tableau(T, tailleTableau);
    afficher_tableau(T, tailleTableau);
    comptage(T, tailleTableau, &nb_min, &nb_maj, &nb_chi);
    printf("\nNombre de minuscules : %d | Nombre de majuscules : %d | Nombre de chiffres : %d", nb_min, nb_maj, nb_chi);
    return 0;
}