//Nom du programme : MENATO_TP1_avec_fonctions
//MENATO Aurélie 19/09/21 Violet Calcul d'une moyenne - avec les fonctions

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
int saisie(int *nb_val, float *elements_saisis); //Sert à saisir le nombre de valeurs et les valeurs
float calcul_moyenne(int *nb_val, float *elements_saisis);

/*======================Codes et fonctions============================================*/
//Codes et Fonctions

int saisie(int *nb_val, float *elements_saisis)
{
    int i = 0;
    if(scanf("%i",nb_val)== 0 || *nb_val < 0)  //scanf renvoie le nombre de lecture bien exécutée, si scanf = 0 alors la valeur saisie n'est pas valide
    {
        printf("Erreur, la saisie n'est pas valide, veuillez relancer le programme \n\n");
        return 0; //La fonction saisie contient une erreur
    }
    else
    {
        printf("Nombre de valeurs %c saisir :\n", 133);
        printf(" %i\n \n",*nb_val);
        printf("Veuillez saisir les valeurs : \n");

        for(i; i < *nb_val ; i++)
        {
            if(scanf("%f",elements_saisis + i)== 0)
            {
                printf("Erreur, la saisie n'est pas valide, veuillez relancer le programme \n\n");
                i = *nb_val;  //on arrête la boucle s'il y a une erreur
                return 0;// Une erreur apparaît dans la fonction
            }
            else
            {
                printf("\n valeur valid%ce : ", 130);
                printf("%f \n",*(elements_saisis + i));
            }
        }
        return 1; //La fonction a bien fait son travail
    }
}

float calcul_moyenne(int *nb_val, float *elements_saisis)
{
//Déclarations locales
    int i = 0;
    float somme;

//Action
    for(i; i< *nb_val; i++)
    {
        somme = somme + *(elements_saisis + i);
    }
    return somme /(*nb_val);
}

/*====================================================================================*/


/*======================Programme Principal===========================================*/
//Programme Principal

int main (void)
{
//Déclaration et initialisation des variables locales
    int *nb_vals = 1;             //nombre de valeur que l'utilisateur veut saisir
    float val_util[MAX] = {0};//Tableau contenant les valeurs, on l'initialise à 0
    int i = 0 ;
    float moyenne;
    float *ptr_tab;//Pointeur du tableau val_util
    int etat_saisie;

//Actions
    printf("Debut du programme \n \n");
    printf("!!! Si vous entrez une lettre %c la place d'un chiffre, vous devrez relancer le programme !!!\n\n", 133);// %c et 133 permettent d'afficher un "à", 130 -> é, etc...
    printf("Combien de valeur(s) souhaitez-vous rentrer ? (entier sup%crieur %c 0) \n \n",130,133);
    printf("Pour cette version du programme, vous %ctes limit%c %c 1000 valeurs \n\n",136,130, 133);
    printf("(Appuyez sur la touche entrer pour valider chaque valeur entr%ce) \n \n",130 );

    ptr_tab = val_util; // pour manipuler le tableau dans les fonctions

    if(saisie(&nb_vals, &ptr_tab)== 1) //S'il n'y a pas d'erreur dans la fonction saisie, on calcule la moyenne
    {
        moyenne = calcul_moyenne(&nb_vals, &ptr_tab);
        printf("Moyenne = %f \n\n", moyenne);
    }//Sinon le programme se termine

    printf("fin du programme\n");
    return 0;
}
/*====================================================================================*/
