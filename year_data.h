#ifndef YEAR_DATA_H
#define YEAR_DATA_H
#include "donnees.h"
#define NB_ANNEES 20
#define ANNEE_DEBUT 2005
#define ANNEE_FIN 2024

typedef struct{
  int annee;
  int nbAccident;
  int indemnes;
  int morts;
  int blessesGraves;
  int blessesLegers;
}StatAnnee;

void traiterAnnee(StatAnnee tab[]);

void afficherAnnee(StatAnnee tab[], Donnee d);

void libererYearData(StatAnnee tab[], int annee);

void menuYearData(StatAnnee tab[]);

//bonus
pireAnnee(){}

meilleurAnnee(){}


#endif
