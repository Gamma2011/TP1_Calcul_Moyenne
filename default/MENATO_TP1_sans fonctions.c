//Nom du programme : MENATO_TP1_sans_fonctions
//MENATO Aurélie 19/09/21 Violet calcul moyenne sans fonctions


/*==========================Headers===================================================*/
//Headers
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//====================================================================================*/


/*==========================Define====================================================*/
//Define
#define MAX 1000 //valeur miximal pour l'indice du tableau
/*====================================================================================*/


/*======================Variables typées==============================================*/
//Variables typées

/*====================================================================================*/


/*=========================Prototypes=================================================*/
//Prototypes
/*====================================================================================*/


/*======================Codes et fonctions============================================*/
//Codes et Fonctions

/*====================================================================================*/


/*======================Programme Principal===========================================*/
//Programme Principal

int main (void)
{
//Déclaration et initialisation des variables locales
    int nb_val;             //nombre de valeur que l'utilisateur veut saisir
    float val_util[MAX] = {0};//Tableau contenant les valeurs, on l'initialise à 0
    int i = 0 ;
    float somme = 0;
    float moyenne = 0;
    int val_tab_ok = 1; //1 si les valeurs saisies de l'utilisateur dans le tableaux sont valides, 0 sinon

//Actions
    printf("Debut du programme \n \n");

    printf("!!! Si vous entrez une lettre %c la place d'un chiffre, vous devrez relancer le programme !!!\n\n", 133);// %c et 133 permettent d'afficher un "à", 130 -> é, etc...
    printf("Combien de valeur(s) souhaitez-vous rentrer ? (entier sup%crieur %c 0) \n \n",130,133);
    printf("Pour cette version du programme, vous %ctes limit%c %c 1000 valeurs \n\n",136,130, 133);
    printf("(Appuyez sur la touche entrer pour valider chaque valeur entr%ce) \n \n",130 );

    if(scanf("%i",&nb_val)== 0 || nb_val < 0) //scanf renvoie le nombre de lecture bien exécutée, si scanf = 0 alors la valeur saisie n'est pas valide(n'est pas un chiffre)
    {
        printf("Erreur, la saisie n'est pas valide, veuillez relancer le programme \n\n");
    }
    else// La saisie du nombre d'éléments est valide
    {
        printf("Nombre de valeurs %c saisir :\n", 133);
        printf(" %i\n \n",nb_val);
        printf("Veuillez saisir les valeurs : \n");

        for(i; i < nb_val ; i++)
        {
            if(scanf("%f",&val_util[i])== 0)
            {
                printf("Erreur, la saisie n'est pas valide, veuillez relancer le programme \n\n");
                i = nb_val;  //on arrête la boucle s'il y a une erreur
                val_tab_ok = 0; // Saisie non valide
            }
            else
            {
                printf("valeur valid%ce : ", 130);
                printf("%f \n",val_util[i]);
                somme = somme + val_util[i];
                val_tab_ok = 1; //saisie valide
            }
        }
        if(val_tab_ok == 1) //ne pas calculer/afficher la moyenne s'il y a une erreur de saisie dans le tableau
        {
            moyenne = somme / nb_val;
            printf("moyenne = %f \n \n", moyenne);
        }
    }

    printf("fin du programme\n");
    return 0;
}
/*====================================================================================*/
