#ifndef AGE_DATA_H
#define AGE_DATA_H

#include "crash_data.h"

#define AGE_MIN 0
#define AGE_MAX 120

#define IDX_HOMME 0
#define IDX_FEMME 1
#define GENRE 2
#define TYPE 3

#define IDX_CONDUCTEUR 0
#define IDX_PASSAGER   1
#define IDX_PIETON     2

typedef struct Age {
    int age;
    int stats[GENRE][TYPE]; //ex : femme piétonne
    struct Age *suivant;
} Age;

Age *creerAge(int age);

/* Recherche un maillon correspondant à un âge (retourne NULL si absent) */
Age *rechercherAge(Age *tete, int age);

/* Insère un nouvel âge dans la liste en gardant l'ordre croissant */
Age *ajouterAge(Age **tete, int age);

/* Met à jour la liste chaînée à partir d'une ligne lue dans le CSV */
void traiterAge(Age **tete, Victime *donnee);

/* Affiche la pyramide des âges en pourcentages selon les choix de l'utilisateur :
 * mode : 1 = par genre (Hommes / Femmes), 2 = par type d'usager, 3 = filtré
 * filtreGenre : 0 = tous, 1 = Homme, 2 = Femme
 * filtreType  : 0 = tous, 1 = Conducteur, 2 = Passager, 3 = Piéton */
void afficherPyramide(const Age *tete, int mode, int filtreGenre, int filtreType);

/* Menu interactif pour laisser l'utilisateur choisir le mode et les filtres */
void menuAgeData(const Age *tete);

/* Libère toute la mémoire de la liste chaînée */
void libererListeAge(Age *tete);

#endif