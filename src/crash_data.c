

Victime creerVictime(int a, int b, int c, int d){
  
  Victime nouveau=malloc(sizeof(Victime));
  
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
