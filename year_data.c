#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "year_data.h"

//initialiser un tableau de 20 cases
void initialiserAnnees(StatAnnee tab[]){
  for(int i=0; i<NB_ANNEES; i++){
    tab[i].annee = ANNEE_DEBUT + i;
    tab[i].nbAccidents = 0;
    tab[i].nbIndemnes = 0;
    tab[i].nbMorts = 0;
    tab[i].nbBlessesGraves = 0;
    tab[i].nbBlessesLegers = 0;
  }
}

void traiterAnnee(StatAnnee tab[], Donne d){
  int indice;
  indice = donnee.year - ANNEE_DEBUT;
  if(indice<0 || indice>= NB_ANNEES){
    printf("Annee invalide\n");
    exit(1);
  }
}

void afficherAnnee(){
  int indice;
  indice = donnee.year - ANNEE_DEBUT;
  if(indice<0 || indice>= NB_ANNEES){
    printf("Annee invalide\n");
    exit(2);
  }
  printf("=========== STATIQUES %d ===========\n", annee);
  printf("Nombre d'accidents : %d\n", tab[indice].nbAccidents);
  printf("Nombre d'indemnes : %d\n", tab[indice].nbIndemnes);
  printf("Nombre d'accident mortel: %d\n", tab[indice].nbMorts);
  printf("Blesses graves : %d\n", tab[indice].nbBlessesGraves);
  printf("Blesses legers : %d\n", tab[indice].nbBlessesLegers);
}

void menuYearData(StatAnnee tab[]){
  int choix = -1;
  while(choix != 0){
    printf("=========== YEAR DATA %d ===========\n", tab[indice].nbIndemnes);
    do{
      printf("Choisissez une année entre 2005 et 2024:\n");
      printf("0 - Quitter :\n");  
      printf("Votre choix:\n");
      scanf("%d", &choix);
      if(choix < 0 || (choix > 1 && choix<2005) || choix > 2024){
        printf("Choix invalide\n");
      }
    }while(choix < 0 || (choix > 1 && choix<2005) || choix > 2024);
    if(choix == 0){
      printf("Fermeture du menu\n");
    }
    else{
      afficherAnnee(tab, choix);
    }
  }

}

void libererYearData(){}

//bonus
void pireAnnee(){}

void meilleurAnnee(){}

