// liste chaînée des victimes 
typedef struct Victime{ 
  int age;
  int genre;
  int type;
  int gravite;
  struct Victime* suivant;
};

// liste chaînée des véhicules
typedef struct Vehicule{ 
  int vehicule_id;
  int cause;
  Victime* victime;
  struct Vehicule* suivant;
};

// représente les accidents du tableau
typedef struct Avl{ 
  int annee;
  int collision_id;
  Vehicule* vehicule;
  int equilibre;
  struct avl* fg
  struct avl* fd;
}Avl;

typedef struct avl* pavl;

// permet de créer victime et ajouter à un véhicule 
Victime* creerVictime(int age, int genre, int type, int gravite);
Victime* ajouterVictime(Vehicule* vehicule, Victime v);

// permet de créer un véhicule et ajouter à un accident
Vehicule* creerVehicule(int identifiant, int cause, Victime* victime);
Vehicule* ajouterVehicule(pavl a, Vehicule vehicule);

// permet de créer un accident et ajouter dans l'avl
pAvl* créerAccident(int ac, Vehicule* v, int e);
pAvl* ajouterAccident(int annee, int collision);

// permet de créer l'avl et d'équilibrer l'arbre lors de l'ajout des accidents
pAvl RotationGauche(pAvl a);
pAvl RotationDroite(pAvl a);
pAvl DoubleRotationGauche(pAvl a);
pAvl DoubleRotationDroite(pAvl a);
pAvl equilibrerAvl(pAvl a);

// permet de rechercher avec le nombre composé de année+collision ( représentant un accident ) dans l'avl
pAvl rechercheAccident( pAvl a, int ac);
