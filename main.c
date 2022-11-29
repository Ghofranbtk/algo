#include <stdio.h>
#include <stdlib.h>
#include"arbre.h"
void DEMOINSERTION(TArbre dico, char *buffer)
{
 dicoAfficher(dico);
/** m5albza hna omour zina w mak ta3refni 3aad .... ****/
    printf("\"%s\" \t->%d\n", "ghof", dicoNbOcc("ghof",dico));
    printf("\"%s\" \t->%d\n", "mohamed", dicoNbOcc("mohamed",dico));
    printf("\"%s\" \t->%d\n", "mediouni", dicoNbOcc("mediouni",dico));
    printf("\"%s\" \t->%d\n", "angular", dicoNbOcc("angular",dico));
    printf("\"%s\" \t->%d\n", "med", dicoNbOcc("med",dico));
    printf("\"%s\" \t->%d\n", "aaaaa", dicoNbOcc("aaaaa",dico));
    printf("\"%s\" \t->%d\n", "djerba", dicoNbOcc("djerba",dico));
    printf("\n");
};

void trouverDansDICO(TArbre dico, char *buffer)
{

    if(dicoNbOcc(buffer, dico) != 0)
    {
        printf("Le mot existe dans le dictionnire");
    }
    else
    {
        printf("Le mot n'existe pas");
    }

}


int main()
{


    int choice = 0;
    int i ;
    TArbre dico;
    char buffer[255];
    dico = arbreConsVide();
    char mot[50];

     strcpy(buffer, "ghofran");
    dicoInsererMot(buffer, &dico);

    strcpy(buffer, "mohamed");
    dicoInsererMot(buffer, &dico);

    strcpy(buffer, "mediouni");
    dicoInsererMot(buffer, &dico);

    strcpy(buffer, "angular");
    dicoInsererMot(buffer, &dico);

    strcpy(buffer, "med");
    dicoInsererMot(buffer, &dico);

    strcpy(buffer, "djerba");
    dicoInsererMot(buffer, dico);

    strcpy(buffer, "aaaaa");
    dicoInsererMot(buffer, dico);

    strcpy(buffer, "ghof");
    dicoInsererMot(buffer, dico);

    /****************************/





    while (choice<=5){

        printf("\n\t");
        printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
        printf("\t\t\t\xB2 MY DICO MENU \xB2");
        printf("\n\t");
        printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n\n");
        printf("\t\xDB\xDB\xDB\xDB\xB2 PRESS 1. Statistique Dictionnaire\n");
        printf("\n\t\xDB\xDB\xDB\xDB\xB2 PRESS 2. Inserer un mot\n");
        printf("\n\t\xDB\xDB\xDB\xDB\xB2 PRESS 3. Afficher Contenu Dictionnaire\n");
        printf("\n\t\xDB\xDB\xDB\xDB\xB2 PRESS 4. Rechercher un mot\n");
        printf("\n\t\xDB\xDB\xDB\xDB\xB2 PRESS 5. Quitter\n\n");
        printf("\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");


        printf("\t--------------------------------------\n");
        printf("\nEnter your choice: ");
        /** verification 3al input number of choice yal ghof***/
        while (scanf("%d", &choice) == 0 || choice > 6)
        {
            printf("Invalid input. Try again\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        };


        switch (choice)
        {

        case 1:
            printf("nombre des mots :%d\n",dicoNbMotsDifferents(dico));
            printf("nombre des mots total :%d\n",dicoNbMotsTotal(dico));
            break;


        case 2:

            printf("Enter un mot: ");
            scanf("%s", mot);
            strcpy(buffer, mot);
            dicoInsererMot(buffer, &dico);

            break;


        case 3:
            DEMOINSERTION(dico, buffer );
            break;

/*** Ghof ken fama error honi mais cv tawa *****/
        case 4:
            printf("Enter un mot a rechercher: ");
            scanf("%s", mot);
            strcpy(buffer, mot);
            trouverDansDICO(dico, buffer );



        case 5:
            exit(0);
        }
    }
    /****************************/


    return 0;

}
