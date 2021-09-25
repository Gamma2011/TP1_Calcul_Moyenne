/**********************************************************************************************************************/
/* INCLUDE FILES                                                                                                      */
/**********************************************************************************************************************/
#include<stdio.h>
#include<stdlib.h>


/**********************************************************************************************************************/
/* CONSTANTS, MACROS                                                                                                  */
/**********************************************************************************************************************/
#define NB_VALUES 1000


/**********************************************************************************************************************/
/* HEADERS FUNCTIONS                                                                                                  */
/**********************************************************************************************************************/
int saisieNombres(double *tableauNombres, int *tailleTableau);

int afficherTableau(double *tableauNombres, int *tailleTableau);

int calculMoyenne(double *moyenneTableau, double *tableauNombres, int *tailleTableau);


/**********************************************************************************************************************/
/* MAIN PROGRAMM                                                                                                      */
/**********************************************************************************************************************/
int main(void)
{
    int tailleTableau = 0;
    double tableauNombres[NB_VALUES] = {0};
    double moyenneTableau = 0;

    while(1)
    {
        if(saisieNombres(tableauNombres, &tailleTableau) < 0)
        {
            printf("\n[ERREUR] Taille du tableau > %d ou <= 0.\n", NB_VALUES);
        }
        else
        {
            afficherTableau(tableauNombres, &tailleTableau);

            calculMoyenne(&moyenneTableau, tableauNombres, &tailleTableau);
        }
    }

    return 0;
}


/**********************************************************************************************************************/
/* FUNCTIONS                                                                                                          */
/**********************************************************************************************************************/
int saisieNombres(double *tableauNombres, int *tailleTableau)
{
    printf("\nSaisissez la taille du tableau (%d max) : ", NB_VALUES);

    scanf("%d", tailleTableau);

    if(*tailleTableau <= 0 || *tailleTableau > NB_VALUES)
    {
        return -1;
    }
    else
    {
        printf("\nVous avez saisie une taille de tableau de %d.\n\n", *tailleTableau);

        for(int i = 0 ; i < *tailleTableau ; i++)
        {
            printf("Saisissez la valeur numero %d : ", (i+1));
            scanf("%lf", &tableauNombres[i]);
        }

        return 0;
    }
}


int afficherTableau(double *tableauNombres, int *tailleTableau)
{
    if(*tailleTableau > 0 && *tailleTableau <= NB_VALUES)
    {
        printf("\n------------------------------\n");
        printf("|   Numero :   |   Valeur :\n");
        printf("------------------------------\n");

        for(int i = 0 ; i < *tailleTableau ; i++)
        {
            printf("|     %.4d     |   %.2lf\n", (i+1), tableauNombres[i]);
            printf("------------------------------\n");
        }

        return 0;
    }
    else
    {
        return -1;
    }
}


int calculMoyenne(double *moyenneTableau, double *tableauNombres, int *tailleTableau)
{
    *moyenneTableau = 0;
    int i = 0;

    if(*tailleTableau > 0 && *tailleTableau <= NB_VALUES)
    {
        for(i = 0 ; i < *tailleTableau ; i++)
        {
            *moyenneTableau += tableauNombres[i];
        }

        *moyenneTableau = *moyenneTableau / i;

        printf("------------------------------\n");
        printf("|   MOYENNE :  %.2lf \n", *moyenneTableau);
        printf("------------------------------\n");;

        return 0;
    }
    else
    {
        return -1;
    }
}