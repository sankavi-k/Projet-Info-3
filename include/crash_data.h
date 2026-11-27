// liste chaînée des victimes 
typedef struct Victime{ 
  int age;
  int genre;
  int type;
  int gravite;
  struct Victime* suivant;
}Victime;

// liste chaînée des véhicules
typedef struct Vehicule{ 
  int vehicule_id;
  int cause;
  Victime* victime;
  struct Vehicule* suivant;
}Vehicule;

// représente les accidents du tableau
typedef struct Avl{ 
  int annee_collision;
  Vehicule* vehicule;
  int equilibre;
  struct avl* fg
  struct avl* fd;
}Avl, * pavl;

// permet de créer victime et ajouter à un véhicule 
Victime* creerVictime(int age, int genre, int type, int gravite);
Victime* ajouterVictime();

// permet de créer un véhicule et ajouter à un accident
Vehicule* creerVehicule(int identifiant, int cause);
Vehicule* ajouterVehicule();

// permet de créer l'avl et d'équilibrer l'arbre lors de l'ajout des accidents
pAvl* RotationGauche(pAvl* a);
pAvl* RotationDroite(pAvl* a);
pAvl* DoubleRotationGauche(pAvl* a);
pAvl* DoubleRotationDroite(pAvl* a);
pAvl* equilibrerAvl(pAvl* a);

// permet de créer un accident et ajouter dans l'avl
pAvl* creerAccident(int annee, int collision_id);
pAvl* ajouterAccident();

// permet de rechercher avec le nombre composé de année+collision ( représentant un accident ) dans l'avl
pAvl* rechercheAccident(pAvl a, int ac);

// permet d'afficher les informations de l'accident trouvé par la fonction rechercherAccident
void afficherDonnees(pAVl a);
