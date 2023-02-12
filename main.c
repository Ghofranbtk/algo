#include <stdio.h>
#include <stdlib.h>
#include"arbre.h"

void DEMOINSERTION(TArbre dico, char *buffer)
{
 dicoAfficher(dico);

    printf("\"%s\" \t -> %d\n", "gallon", dicoNbOcc("gallon",dico));
    printf("\"%s\" \t\t -> %d\n", "mumu", dicoNbOcc("mumu",dico));
    printf("\"%s\" \t -> %d\n", "munier", dicoNbOcc("munier",dico));
    printf("\"%s\" \t -> %d\n", "gastro", dicoNbOcc("gastro",dico));
    printf("\"%s\" \t -> %d\n", "lespine", dicoNbOcc("lespine",dico));
    printf("\"%s\" \t\t -> %d\n", "ghof", dicoNbOcc("ghof",dico));
    printf("\n");

};

void trouverDansDICO(TArbre dico, char *buffer)
{

    if(dicoNbOcc(buffer, dico) != 0)
    {
        printf("Le mot existe dans le dictionnire\n");
    }
    else
    {
        printf("Le mot n'existe pas\n");
    }

}


int main()
{


    int choice = 0;
    int i ;
    TArbre dico;
    char buffer[300],chaine[350],welcome[5000];
    dico = arbreConsVide();
    char mot[50];

    strcpy(buffer, "gallon");
    dicoInsererMot(buffer, &dico);

    strcpy(buffer, "munier");
    dicoInsererMot(buffer, &dico);

    strcpy(buffer, "abenia");
    dicoInsererMot(buffer, &dico);

    strcpy(buffer, "munier");
    dicoInsererMot(buffer, &dico);

    strcpy(buffer, "mumu");
    dicoInsererMot(buffer, &dico);

    strcpy(buffer, "alpha");
    dicoInsererMot(buffer, &dico);

    strcpy(buffer, "alphabeta");
    dicoInsererMot(buffer, &dico);

    strcpy(buffer, "al");
    dicoInsererMot(buffer, &dico);

strcpy(welcome,"#   ______    _                      _              __\n#  |_   _ `. (_)                    / |_           [  |\n#    | | `. \\__  .---.  .--.  _____`| |-.---. .---. | |--.\n#    | |  | [  |/ /'`\\/ .'`\\ |______| |/ /__\\/ /'`\\]| .-. |\n#   _| |_.' /| || \\__.| \\__. |      | || \\__.| \\__. | | | |\n#  |______.'[___'.___.''.__.'       \\__/'.__.'.___.[___]|__] \n#\t\t\t\t\t\t\t\t BY : Ghofran , Raoua and Nermine\n");



printf("%s",welcome);
printf("\n");
printf("\n");
    while (choice<=5){

printf("\t,---------------------------------------------------.\n");
printf("\t| ,-----------------------------------------------.  |\n");
printf("\t| |                                                | |\n");
printf("\t| |                   \xB2 Menu \xB2                     | |\n");
printf("\t| |                                                | |\n");
printf("\t| |                                                | |\n");
printf("\t| |  \xB2 PRESS 1. Statistics                         | |\n");
printf("\t| |                                                | |\n");
printf("\t| |  \xB2 PRESS 2. Insert Word                        | |\n");
printf("\t| |                                                | |\n");
printf("\t| |  \xB2 PRESS 3. Display Dictionary Content         | |\n");
printf("\t| |                                                | |\n");
printf("\t| |  \xB2 PRESS 4. Search                             | |\n");
printf("\t| |                                                | |\n");
printf("\t| |  \xB2 PRESS 5. Quit                               | |\n");
printf("\t| |                                                | |\n");
printf("\t| |                                                | |\n");
printf("\t| |................................................| |\n");
printf("\t| |  _  :                             '      :  _  | |\n");
printf("\t| | |_| :                                    : |_| | |\n");
printf("\t| |  _  :_            DICO-TECH             _:  _  | |\n");
printf("\t| | |_| :.)           ----------      .    (.: |_| | |\n");
printf("\t| '-----.....____________________________.....-----' |\n");
printf("\t----------------------------------------------------.");

   printf("\nEnter your choice: ");

        while (scanf("%d", &choice) == 0 || choice > 6)
        {
            printf("Invalid input. Try again\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        };



        switch (choice)
        {

        case 1:
            printf("number of words without redundancy :%d\n",dicoNbMotsDifferents(dico));
            printf("Total word count :%d\n",dicoNbMotsTotal(dico));
            break;

        case 2:

            printf("Enter a word: ");
            scanf("%s", mot);
            strcpy(buffer, mot);
            dicoInsererMot(buffer, &dico);

            break;


        case 3:
            DEMOINSERTION(dico, buffer );
            break;


        case 4:
            printf("Enter a word searched : ");
            scanf("%s", mot);
            strcpy(buffer, mot);
            trouverDansDICO(dico, buffer );
              break;

        case 5:
            exit(0);
        }

    }

    return 0;

}
