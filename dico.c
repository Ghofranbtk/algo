#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "dico.h"

/*************** functions ****************/

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
           /**on commance par la branche droite vers la branche gauche */
            if (pa->droite != NULL)
            {

                diplayDico(mot, pa->droite);
            }

            if (pa->gauche != NULL)
            {
               /**creation du mot lit dans le variable mot pour le afficher lorsque on atteind  '\0' */
                strcat(mot, (char[2])
                {
                    pa->info, '\0'
                });
                diplayDico(mot, pa->gauche);
                /**on continue la lecture a gauche dans le meme mot */
            }

            mot[strlen(mot) - 1] = '\0';
        }
        else
        {
            printf("\t|          %i         |        %s", pa->nb,mot);
            /** boucle utiliser our ameliorer l'affichage du dictionnaire */
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
* fonction "dicoInsererMot"
* @param mot pointeur sur le mot
* @param pos position de la lettre dans le mot
* @param pa arbre
**/

void dicoInsererMot(char mot[], TArbre *pa)
{
    if (*pa == NULL)
    {
        /** si noued racine est nulle on creer un nouveau noeud avec la premier caractere de mot
        * si ce caractere est /0 on increment nb a 1 pour indique que c'est la fin du chaine
        * sinon on met la valeur 0
        */
        *pa = arbreCons(mot[0], mot[0] == '\0' ? 1 : 0, arbreConsVide(), arbreConsVide());

       /** inserer les letrres en sous arbre gauche si le premier caracter diff de \0*/
        if (mot[0] != '\0')
        {
            dicoInsererMot(mot + 1, &(*pa)->gauche);
        }
    }
    else
    {
        /** si la premier lettre du mot est identique a la racine de l'arbre   */
        if (mot[0] == arbreRacineLettre(*pa))
        {
            /**, insérez récursivement les lettres restantes du mot dans le sous-arbre gauche du noeud racine */

            if (mot[0] == '\0')
            {
                (*pa)->nb = (*pa)->nb + 1;
            }
            else
            {
                dicoInsererMot(mot + 1, &(*pa)->gauche);
            }
        }
        /** Si la première lettre du mot est supérieure à la première lettre du noeud racine */
        else if ((int)arbreRacineLettre(*pa) < (int)mot[0])
        {
            /** insérez récursivement le mot dans le sous-arbre droit du noeud racine */
            dicoInsererMot(mot, &(*pa)->droite);
        }
        else
        {
            /** Si la première lettre du mot est inférieure à la première lettre du noeud racine */
            /** créez un nouveau noeud avec la première lettre du mot et insérez-le comme nouvelle racine */
            /** le pointeur gauche du nouveau noeud prend l'ancienne noeud racine */
            TArbre new_node = arbreCons(mot[0], mot[0] == '\0' ? 1 : 0, NULL, *pa);
            if (mot[0] != '\0')
            {
                /** insérez récursivement les lettres restantes du mot dans le sous-arbre gauche */
                dicoInsererMot(mot + 1, &new_node->gauche);
            }
            *pa = new_node;
        }
    }
}

/**
* Fonction pour chercher l'existance d'un mot
* @param mot pointeur sur le mot
* @param i position de caractere dans le mot
* @param pa arbre de dictionnaire
**/
TArbre* findWord(char * mot, int i, TArbre pa)
{
    /** test si arbre non vide */
    if (pa != NULL)
    {
        /** tant que position i est < au mot  */
        if (i < strlen(mot))
        {
            if (mot[i] == pa -> info)
            {
                /**tant que on lit correctement les chararteres on passe a gauche et on incremente i+1 */
                findWord(mot, i + 1, pa -> gauche);
            }
            else
            {
                /** sinon on passe a la branche droite de l'arbre    */
                findWord(mot, i, pa -> droite);
            }
        }
        else
        {
            if (pa -> info == '\0')
            {
                return pa; /** si mot existe on retourne un pointeur sur l'\0' du mot recherchée*/
            }
        }
    }
    else
    {

        return NULL; /** Si on n'a PAS trouver le mot*/

    }

}
/************* implemented functions "dicoAfficher" ***********/
/**
* Fonction pour afficher l'entete du tableau  et executer la fonction d'affichage diplayDico();
* @param pa arbre
**/
void dicoAfficher(TArbre pa)
{
    char tempChar[255]="";
     printf("\n");
    printf("\t-------------------------------------------------------------------------\n");
    printf("\t| Nombre d occurence |                     Mot                          |\n");
    printf("\t-------------------------------------------------------------------------\n");
     diplayDico(&tempChar,pa);
    printf("\t-------------------------------------------------------------------------\n");
     printf("\n");
}

/************* implemented functions "dicoNbOcc" ***********/
/** Fonction pour calculer le nombre d'occurences d'un mot dans l'arbre (UNIQUES) appelée dans la main.c
* @param pa arbre
* @param mot pointeur sur le mot à rechercher
**/
int dicoNbOcc(char *mot, TArbre a)
{
    /**on verifie si le mot existe dan le dictionnaire*/
    TArbre  t = findWord(mot, 0, a);
    if (t)
    {
        /** si existe le mot on retourne le nbr d'occurance */
        return t->nb;
    }
    else
    {
        return 0;
    }

}

/************* implemented functions " dicoNbMotsDifferents " ***********/
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
            /**calcule le nombre des mots dans les branches a gauche et a droite et on ajoute 1 en cas d'existance*/
            return (1 + (dicoNbMotsDifferents(a->droite)+ dicoNbMotsDifferents(a->gauche)));
        }
        else
        {

            return dicoNbMotsDifferents(a->droite)+dicoNbMotsDifferents(a->gauche);
        }
    }
    return 0;

}

/************* implemented functions " dicoNbMotsTotal " ***********/
/** Fonction pour calculer le nombre total des mots
* @param pa arbre
**/
int dicoNbMotsTotal(TArbre a)
{
    if(a!=NULL)
    {
        if(a->info =='\0')
        {
            /** en cas de fin de mot on ajoute le nbr d'occurance et on calcule le nbr de partie gauche et droite */
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
/**********
* @param motPioche mot a ajouter
*
*/

int piocherMot(char *motPioche)
{
      /** Le pointeur de fichier qui va contenir notre fichier */
    FILE* dico = NULL;
    int nombreMots = 0, numMotChoisi = 0, i = 0;
    int caractereLu = 0;
    dico = fopen("dico.txt", "r");
    /** On ouvre le dictionnaire en lecture seule*/
    /** On vérifie si on a réussi à ouvrir le dictionnaire*/
    if (dico == NULL) /** Si on n'a PAS réussi à ouvrir le fichier*/
    {
        printf("\nImpossible de charger le dictionnaire de mots");
        return 0; /** On retourne 0 pour indiquer que la fonction a échoué */
    }
/** On compte le nombre de mots dans le fichier (il suffit de compter les entrées */
    do
    {
        caractereLu = fgetc(dico);
        if (caractereLu == '\n')
            nombreMots++;
    }
    while(caractereLu != EOF);
    numMotChoisi = nombreAleatoire(nombreMots); /** On pioche un mot au hasard
// On recommence à lire le fichier depuis le début. On s'arrête lorsqu'on est arrivé au bon mot*/
    rewind(dico);
    while (numMotChoisi > 0)
    {
        caractereLu = fgetc(dico);
        if (caractereLu == '\n')
            numMotChoisi--;
    }
    /** Le curseur du fichier est positionné au bon endroit.
    On n'a plus qu'à faire un fgets qui lira la ligne */
    fgets(motPioche, 100, dico);
/** On vire le \n à la fin*/
    motPioche[strlen(motPioche) - 1] = '\0';
    fclose(dico);
    return 1; /** Tout s'est bien passé, on retourne 1 */
}


/************* implemented functions " nombreAleatoire " ***********/
/**********
* @param nombreMax nbr par hazard maximale
*
*/

int nombreAleatoire(int nombreMax)
{
    srand(time(NULL));
    return (rand() % nombreMax);
}
