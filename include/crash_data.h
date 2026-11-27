
typedef struct Victime{ // liste chaînée des victimes 
  int age;
  int genre;
  int type;
  int gravite;
  struct Victime* suivant;
};

typedef struct Vehicule{ // liste chaînée des véhicules
  int vehicule_id;
  int cause;
  Victime* victime;
  struct Vehicule* suivant;
};

typedef struct avl{ // noeud de l'avl
  int annee_collision;
  Vehicule* vehicule;
  int equilibre;
  struct avl* fg
  struct avl* fd;
}avl;

typedef struct avl* pavl;

Victime* creerVictime(int age, int genre, int type, int gravite);
Victime* ajouterVictime(pavl* a, Victime v);
Vitime* supprimer
