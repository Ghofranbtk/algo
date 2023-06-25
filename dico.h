#ifndef DICO_H
#define DICO_H

#include"arbre.h"


void dicoInsererMot(char *mot, TArbre *pa);
void dicoAfficher(TArbre pa);
int dicoNbOcc(char *mot, TArbre a);
int dicoNbMotsDifferents(TArbre a);


/**--------------------*/
int piocherMot(char *motPioche);
int nombreAleatoire(int nombreMax);

#endif
