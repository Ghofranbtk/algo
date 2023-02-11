#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "dico.h"





/*********** useful functions ***********/

/**Fonction pour afficher le dictionnaire dans un tableau
 * @param mot  pointeur sur le mot a afficher
 * @param pa pointeur sur arbre qui contient le mot
**/
void diplayDico(char *mot, TArbre pa)
{
    int i;
/**verifier si l'arbre donné en parametre n'est pas vide*/
    if (pa != NULL)
    {
        if (pa->info != '\0')
        {
            //on commance par la branche droite vers la branche gauche
            if (pa->droite != NULL)
            {

                diplayDico(mot, pa->droite);
            }

            if (pa->gauche != NULL)
            {
                //creation du mot lit dans le variable mot pour le afficher lorsque on atteind  '\0'
                strcat(mot, (char[2])
                {
                    pa->info, '\0'
                });
                diplayDico(mot, pa->gauche);//on continue la lecture a gauche dans le meme mot
            }

            mot[strlen(mot) - 1] = '\0';
          //  printf("%s**\n",mot);
        }
        else
        {
            printf("\t|          %i         |        %s", pa->nb,mot);
            //boucle utiliser our ameliorer l'affichage du dictionnaire
            for(i=0; i<50-8-strlen(mot); i++)
            {
                printf(" ");
            }
            printf("|\n");
            if (pa->droite != NULL)
                diplayDico(mot, pa->droite);

        }
    }
}

/**
* fonction d'insertion apres verification
* @param mot pointeur sur le mot
* @param pos position de la lettre dans le mot
* @param pa arbre
**/
void pushDico(char * mot, int pos, TArbre pa)
{

    if (arbreEstVide(pa))   //test sur l'arbre vide pour la creation du nouveau noeud si oui
    {
        if (pos <= strlen(mot))
        {
            if ((mot[pos] != pa -> info) && (arbreFilsGauche(pa)!= NULL))
            {
                if (arbreFilsDroit(pa) != NULL)  // decente a droite pour l'insertion du nouveau characteres
                {
                    pushDico(mot, pos, pa -> droite);
                }
                else     //creation du noeud a droit si elle n'existe pas
                {
                    TArbre t=arbreCons(mot[pos], 0, arbreConsVide(), arbreConsVide());
                    pa -> droite = t;
                    pushDico(mot, pos, pa -> droite);
                }
            }
            else
            {
                if (arbreFilsGauche(pa)  != NULL)
                {
                    //passant a gauche tantque on lit correctement les characteres
                    pushDico(mot, pos + 1, pa -> gauche);
                }
                else
                {

                    if (pa -> info == '\0')   // pour les cas complexe "ce / ces"
                    {
                        TArbre t=arbreCons(mot[pos], 0, arbreConsVide(), arbreConsVide());
                        pa -> droite = t;
                        pushDico(mot, pos, pa -> droite);
                    }
                    else
                    {
                        if (mot[pos + 1] != '\0')
                        {
                            // dans le cas que le mot n'est pas finis on continue l'insertion des characteres a gauche
                            TArbre t=arbreCons(mot[pos + 1], 0, arbreConsVide(), arbreConsVide());
                            pa -> gauche = t;
                            pushDico(mot, pos + 1, pa -> gauche);
                        }
                        else    //si on est dans la fin du mot on insert le '\0' dans une nouvelle noeud a gauche
                        {
                            TArbre t=arbreCons('\0', 1, arbreConsVide(), arbreConsVide());
                            pa -> gauche = t;

                        }

                    }
                }

            }

        }

    }
    else
    {
//creation du nouveau noeud
        if (pos < strlen(mot))
        {
            TArbre t=arbreCons(mot[pos], pos, arbreConsVide(), arbreConsVide());
            pa = t;
            pushDico(mot, pos + 1, pa -> gauche);
        }

    }

}

// Recherche d'un mot dans le dic
//used to help us in the insert and other stuff

/**
* Fonction pour chercher l'existance d'un mot
* @param mot pointeur sur le mot
* @param i position de la lettre dans le mot
* @param pa arbre
**/
TArbre* findWord(char * mot, int i, TArbre pa)
{
    if (pa != NULL)
    {
        if (i < strlen(mot))
        {
            if (mot[i] == pa -> info)
            {
                //tant que on lit correctement les chararteres on passe a gauche et on incremente i
                findWord(mot, i + 1, pa -> gauche);
            }
            else
            {
                findWord(mot, i, pa -> droite);
            }
        }
        else
        {
            if (pa -> info == '\0')
            {
                return pa; // pointeur sur l'\0' du mot recherchée
            }
        }
    }
    else
    {
        //printf("AUCUN MOT TROUVE\n");
        return NULL; //  Si on n'a PAS trouv le mot

    }

}



/************* implemented functions ***********/

/**
* Fonction pour inserer un nouveau mot (appelée dans le main.c) après la verification de son existance
* @param mot pointeur sur le mot
* @param pa pointeur sur arbre
**/
void dicoInsererMot(char * mot, TArbre  *pa)
{

    TArbre t = findWord(mot, 0, pa);

    if (t)
    {
        ++t -> nb;
    }
    else
    {
        pushDico(mot, 0, pa);
    }


}

/**
* Fonction pour afficher l'entete du tableau  et executer la fonction d'affichage diplayDico();
* @param pa arbre
**/
void dicoAfficher(TArbre pa)
{
    char tempChar[255]="";
    printf("\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    printf("\t| Nombre d occurence |                     Mot                          |\n");
    printf("\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    diplayDico(&tempChar,pa);
    printf("\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
}

/**
* Fonction pour calculer le nombre d'occurences d'un mot dans l'arbre (UNIQUES) appelée dans la main.c
* @param pa arbre
* @param mot pointeur sur le mot à rechercher
**/
int dicoNbOcc(char *mot, TArbre a)
{
    //on verifie si le mot existe dan le dictionnaire
    TArbre  t = findWord(mot, 0, a);
    if (t)
    {
        return t->nb;
    }
    else
    {
        return 0;
    }

}

/**
* Fonction pour calculer le nombre de mots uniques
* @param pa arbre
**/
int dicoNbMotsDifferents(TArbre a)
{
    if(a!=NULL)
    {
        if(a->info =='\0')
        {
            //calcule le nombre des mots dans les branches a gauche et a droite
            return (1 + (dicoNbMotsDifferents(a->droite)+ dicoNbMotsDifferents(a->gauche)));
        }
        else
        {

            return dicoNbMotsDifferents(a->droite)+dicoNbMotsDifferents(a->gauche);
        }
    }
    return 0;

}

/**
* Fonction pour calculer le nombre total des mots
* @param pa arbre
**/
int dicoNbMotsTotal(TArbre a)
{
    if(a!=NULL)
    {
        if(a->info =='\0')
        {
            return ( a->nb + (dicoNbMotsTotal(a->droite)+ dicoNbMotsTotal(a->gauche)));
        }
        else
        {
            return dicoNbMotsTotal(a->droite)+dicoNbMotsTotal(a->gauche);
        }
    }
    return 0;
}


/************* implemented functions " piocherMot " ***********/


int piocherMot(char *motPioche)
{
    FILE* dico = NULL; // Le pointeur de fichier qui va contenir notre fichier
    int nombreMots = 0, numMotChoisi = 0, i = 0;
    int caractereLu = 0;
    dico = fopen("dico.txt", "r"); // On ouvre le dictionnaire en lecture seule
// On vérifie si on a réussi à ouvrir le dictionnaire
    if (dico == NULL) // Si on n'a PAS réussi à ouvrir le fichier
    {
        printf("\nImpossible de charger le dictionnaire de mots");
        return 0; // On retourne 0 pour indiquer que la fonction a échoué
// À la lecture du return, la fonction s'arrête immédiatement.
    }
// On compte le nombre de mots dans le fichier (il suffit de compter les
// entrées \n
    do
    {
        caractereLu = fgetc(dico);
        if (caractereLu == '\n')
            nombreMots++;
    }
    while(caractereLu != EOF);
    numMotChoisi = nombreAleatoire(nombreMots); // On pioche un mot au hasard
// On recommence à lire le fichier depuis le début. On s'arrête lorsqu'on est arrivé au bon mot
    rewind(dico);
    while (numMotChoisi > 0)
    {
        caractereLu = fgetc(dico);
        if (caractereLu == '\n')
            numMotChoisi--;
    }
    /* Le curseur du fichier est positionné au bon endroit.
    On n'a plus qu'à faire un fgets qui lira la ligne */
    fgets(motPioche, 100, dico);
// On vire le \n à la fin
    motPioche[strlen(motPioche) - 1] = '\0';
    fclose(dico);
    return 1; // Tout s'est bien passé, on retourne 1
}

int nombreAleatoire(int nombreMax)
{
    srand(time(NULL));
    return (rand() % nombreMax);
}
