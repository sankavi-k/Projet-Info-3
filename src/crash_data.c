#include <stdio.h>
#include <stdlib.h>
#include <"crash_data.h">

// CREATION DE L'AVL

// ETAPE 1 : CREER LES VICTIMES, VEHICULE ET ACCIDENTS ( NOEUD DE L'AVL ) pour ensuite pouvoir mettre les données du fichier

Victime* creerVictime(int a, int b, int c, int d){
  
  Victime* nouveau=malloc(sizeof(Victime));
  
  if ( nouveau == NULL ){
    exit(1);
  }
  
  nouveau->age=a;
  nouveau->genre=b;
  nouveau->type=c;
  nouveau->gravite=d;
  nouveau->suivant=NULL;
  
  return nouveau;
}

Vehicule* creerVehicule(int identifiant, int cause){
  
  Vehicule* vehicule=malloc(sizeof(Vehicule));
  
  if(vehicule==NULL){
    exit(1);
  }
  
  vehicule->vehicule_id=identifiant;
  vehicule->cause=cause;
  vehicule->victime=NULL;
  vehicule->suivant=NULL;
  
  return vehicule;
}


pAvl* creerAccident(int annee, int collision_id){
	pAvl nouveau=malloc(sizeof(pAvl));
	if(pAvl==NULL){
		exit (1);
	}
	nouveau->annee_collision=( faire en sorte de faire annee + collision_id );
	nouveau->vehicule=NULL;
  	nouveau->equilibre=1;
  	nouveau->fg=NULL;
  	nouveau->fd=NULL;
  	return nouveau;
}

// ETAPE 2 : LES FONCTIONS POUR EQUILIBRER L'ARBRE ET CREER UN AVL

pAvl RotationGauche(pAvl a){
  if(a==NULL){
    exit(1);
  }
  pAvl pivot = a->fd;
  a->fd = pivot->fg;
  pivot->fg = a;
  int eq_a = a->equilibre;
  int eq_p = pivot->equilibre;
  a->equilibre = eq_a - max(eq_p, 0) - 1;
  pivot->equilibre = min(eq_a - 2, eq_a + eq_p -2, eq_p -1);
  a = pivot;
  return a;
}

pAvl RotationDroite(pAvl a){
  if(a==NULL){
    exit(1);
  }
  pAvl pivot = a->fg;
  a->fg = pivot->fd;
  pivot->fd = a;
  int eq_a = a->equilibre;
  int eq_p = pivot->equilibre;
  a->equilibre = eq_a - max(eq_p, 0) - 1;
  pivot->equilibre = min(eq_a - 2, eq_a + eq_p -2, eq_p -1);
  a = pivot;
  return a;
}

pAvl DoubleRotationGauche(pAvl a){
  a->fd = rotationDroite(a->fd);
  return rotationGauche(a);
}

pAvl DoubleRotationDroite(pAvl a){
  a->fg = rotationGauche(a->fg);
  return rotationDroite(a);
}

pAvl equilibrerAvl(pAvl a){
	if(a->equilibre>=2){
		if(a->fd->equilibre>=0){
			return DoubleRotationGauche(pAvl a);
		}
		else{
			return DoubleRotationGauche(pAvl a);
		}
	}
	else if(a->equilibre<=-2){
		if(a->fg->equilibre<=0){
			return RotationDroite(a);
		}
		else{
			return DoubleRotationDroite(a);
		}
	}
	return a;
}

// ETAPE 3 : AJOUTER LES DONNEES DU FICHIER DANS L'ARBRE





// ETAPE 4 : RECHERCHER L'ACCIDENT AVEC IDENTIFIANT DONNE PAR L'UTILISATEUR 

pAvl rechercheAccident( pAvl a, int ac){
	if(a==NULL){
		return NULL;
	}
	else if(ac==a->annee_collision){
		return a;
	}
	else if (ac<a->annee_collision){
		return recherche(a->fg, ac);
	}
	else{
		return recherche(a->fd, ac);
	}
}

// ETAPE 5 : AFFICHER TOUTES LES DONNEES LIES A L'ACCIDENTS ( liste de véhicules (+infos) et de victimes (+infos) à chaque véhicule





