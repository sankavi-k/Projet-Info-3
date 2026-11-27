#include <"stdio.h">



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

Victime* ajouterVictime(Vehicule* vehicule, Victime v){}

Vehicule* creerVehicule(int identifiant, int cause, Victime* victime){}
Vehicule* ajouterVehicule(pavl a, Vehicule vehicule){}

pAvl RotationGauche(pAvl a){}
pAvl RotationDroite(pAvl a){}
pAvl DoubleRotationGauche(pAvl a){}
pAvl DoubleRotationDroite(pAvl a){}
pAvl equilibrerAvl(pAvl a){}

pAvl* creerAccident(int ac, Vehicule* v, int e){}
pAvl* ajouterAccident(int annee, int collision){}

pAvl rechercheAccident( pAvl a, int ac){}
