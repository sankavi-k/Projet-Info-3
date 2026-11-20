#ifndef YEAR_DATA_H
#define YEAR_DATA_H

#define NB_ANNEES 20
#define ANNEE_DEBUT 2005
#define ANNEE_FIN 2024

//Structure pour stocker les statistiques d'une année
typedef struct {
    int annee;
    int nbAccidents;
    int nbIndemnes;
    int nbMorts;
    int nbBlessesGraves;
    int nbBlessesLegers;
} StatAnnee;

// Structure pour représenter les données utiles d'une ligne du CSV
typedef struct{
    int annee2;
    int collision_id;
    int gravite;
}Enregistrement;

void initialiserAnnees(StatAnnee tab[]);
void traiterAnnee(StatAnnee tab[], Enregistrement donnee);
void afficherAnnee(StatAnnee tab[], int anneeChoisie);
void menuYearData(StatAnnee tab[]);

// Bonus (déclarations uniquement, sans corps dans le .h)
void pireAnnee(StatAnnee tab[]);
void meilleurAnnee(StatAnnee tab[]);

#endif