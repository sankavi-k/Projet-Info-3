#include <stdio.h>
#include <stdlib.h>
#include <"crash_data.h">



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


pAvl RotationGauche(pAvl a){}

pAvl RotationDroite(pAvl a){}

pAvl DoubleRotationGauche(pAvl a){}

pAvl DoubleRotationDroite(pAvl a){}

pAvl equilibrerAvl(pAvl a){}


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



pAvl rechercheAccident( pAvl a, int ac){}
