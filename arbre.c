#include"arbre.h"

#include<stdio.h>

TArbre arbreConsVide()
{

    TArbre *t;
    return t;
}

int arbreEstVide(TArbre a)
{
    if (a == NULL)
    {
        return 0;
    }
    return 1;
}

TArbre arbreCons(char c, int n, TArbre  fg, TArbre  fd)
{

    TArbre tempNoeud = (TArbre) malloc(1 * sizeof(struct Noeud));
    tempNoeud -> info = c;
    tempNoeud -> nb = n;
    tempNoeud -> droite = fd;
    tempNoeud -> gauche = fg;
    return tempNoeud;
}

TArbre  arbreFilsGauche(TArbre  a)
{
    if (arbreEstVide(a) != 0)
    {
        return a->gauche;
    }
    return arbreConsVide();
}

TArbre arbreFilsDroit(TArbre  a)
{
    if (arbreEstVide(a) != 0)
    {
        return a->droite;
    }
    return arbreConsVide();
}

char arbreRacineLettre(TArbre a)
{
    if (arbreEstVide(a) != 0)
    {
        return a->info;
    }
    return NULL;

}

int arbreRacineNbOcc(TArbre a)
{
    if (arbreEstVide(a) != 0)
    {
        return a->nb;
    }
    return NULL;
}

void arbreSuppr(TArbre a)
{
    //pour conserver le noeud orignal pour acceder a les fils
    struct Noeud *tempNoued=a;

    if(a!= NULL)
    {
        arbreSuppr(tempNoued -> droite);
        arbreSuppr(tempNoued ->gauche);
        free(tempNoued);//supression du l'espace memoire
    }
    else
    {
        printf("TArbre est null\n");
        return;
    }


}


