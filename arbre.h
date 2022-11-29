#ifndef ARBRE_H_
#define ARBRE_H_

typedef struct Noeud {
  struct Noeud * droite;
  struct Noeud * gauche;
  char  info;
  int nb;
};
typedef struct Noeud *TArbre;


TArbre arbreConsVide(void);
int arbreEstVide(TArbre a);
TArbre arbreCons(char c, int n, TArbre fg, TArbre fd);
char arbreRacineLettre(TArbre a);
int arbreRacineNbOcc(TArbre a);
TArbre arbreFilsGauche(TArbre a);
TArbre arbreFilsDroit(TArbre a);
void arbreSuppr(TArbre a);

#endif
