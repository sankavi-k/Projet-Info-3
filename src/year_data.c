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

void traiterAnnee(StatAnnee tab[], Enregistrement d){ //d pour donnee
    int indice = d.annee2 - ANNEE_DEBUT;
    if(indice < 0 || indice >= NB_ANNEES){
        printf("Erreur : Annee hors intervalle (2005-2024) detectee dans les donnees\n");
        exit(3); // Ignore les années hors intervalle 2005-2024
    }
    //Incrémentation selon la gravité (1: indemne, 2: tué, 3: blessé grave, 4: léger)
    tab[indice].nbAccidents++;
    switch(d.gravite){
        case 1:
            tab[indice].nbIndemnes++;
            break;
        case 2:
            tab[indice].nbMorts++;
            break;
        case 3:
            tab[indice].nbBlessesGraves++;
            break;
        case 4:
            tab[indice].nbBlessesLegers++;
            break;
        default:
            break;
    }
}

void afficherAnnee(StatAnnee tab[], int anneeChoisie){
    int indice = anneeChoisie - ANNEE_DEBUT;
    if(indice < 0 || indice >= NB_ANNEES){
        printf("Annee invalide\n");
        return;
    }
    printf("\n=========== STATISTIQUES %d ===========\n", anneeChoisie);
    printf("Nombre d'accidents : %d\n", tab[indice].nbAccidents);
    printf("Nombre d'indemnes : %d\n", tab[indice].nbIndemnes);
    printf("Nombre de morts : %d\n", tab[indice].nbMorts);
    printf("Blesses graves : %d\n", tab[indice].nbBlessesGraves);
    printf("Blesses legers : %d\n", tab[indice].nbBlessesLegers);
    printf("=======================================\n\n");
}

void menuYearData(StatAnnee tab[]){
  int choix = -1;
  while(choix != 0){
    do{
      printf("Choisissez une année entre 2005 et 2024:\n");
      printf("0 - Quitter :\n");  
      printf("Votre choix:\n");
      scanf("%d", &choix);
      if(choix != 0 && (choix < 2005 || choix > 2024)){
        printf("Choix invalide\n");
        while(getchar() != '\n'); // Vider le buffer
        continue;
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

//bonus

void pireAnnee(StatAnnee tab[]){
  int pire = 0; // On initialise avec la première année
    for(int i = 1; i<NB_ANNEES; i++){
        if(tab[i].nbAccidents > tab[pire].nbAccidents){
            pire = i;
        }
    }
    printf("\n--- PIRE ANNEE (Plus d'accidents) ---\n");
    printf("Annee : %d\n", tab[pire].annee);
    printf("Nombre d'accidents : %d\n", tab[pire].nbAccidents);
    printf("Nombre de morts : %d\n", tab[pire].nbMorts);
    printf("-------------------------------------------\n\n");
}

//On définit "meilleure" par le moins d'accidents total (ou tu peux changer par nbMorts)
void meilleurAnnee(StatAnnee tab[]){
  int meilleur = 0; // On initialise avec la première année
    for(int i = 1; i<NB_ANNEES; i++){
        if(tab[i].nbAccidents < tab[meilleur].nbAccidents){
            meilleur = i;
        }
    }
    printf("\n--- MEILLEURE ANNEE (Moins d'accidents) ---\n");
    printf("Annee : %d\n", tab[meilleur].annee);
    printf("Nombre d'accidents : %d\n", tab[meilleur].nbAccidents);
    printf("Nombre de morts : %d\n", tab[meilleur].nbMorts);
    printf("-------------------------------------------\n\n");
}

