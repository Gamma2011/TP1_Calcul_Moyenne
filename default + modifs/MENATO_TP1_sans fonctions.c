#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

int main (void)
{

    int nb_val; 
    float val_util[MAX] = {0};
    int i = 0 ;
    float somme = 0;
    float moyenne = 0;
    int val_tab_ok = 1;

    printf("Debut du programme \n \n");

    printf("!!! Si vous entrez une lettre à la place d'un chiffre, vous devrez relancer le programme !!!\n\n"); // [JEAN] -> Ca complique ton code, reste simple (même si l'idée est bien pensée pour la console Windows)
    printf("Combien de valeur(s) souhaitez-vous rentrer ? (entier supérieur à 0) \n \n"); // [JEAN] -> idem
    printf("Pour cette version du programme, vous êtes limité à 1000 valeurs \n\n"); // [JEAN] -> idem
    printf("(Appuyez sur la touche entrer pour valider chaque valeur entrée) \n \n"); // [JEAN] -> idem

    if(scanf("%i",&nb_val)== 0 || nb_val < 0) // [JEAN] -> ne brule pas les étapes, fais le scanf séparément et ensuite tu met nb_val seul dans le if
    {
        printf("Erreur, la saisie n'est pas valide, veuillez relancer le programme \n\n");
    }
    else
    {
        printf("Nombre de valeurs %c saisir :\n", 133);
        printf(" %i\n \n",nb_val);
        printf("Veuillez saisir les valeurs : \n");

        for(i = 0; i < nb_val ; i++)
        {
            scanf("%f", &val_util[i]);

            if(val_util[i] == 0) // [JEAN] -> Pareil ici, le scanf séparément et ensuite le val_util[i] seul dans le if
            {
                printf("Erreur, la saisie n'est pas valide, veuillez relancer le programme \n\n");
                i = nb_val;
                val_tab_ok = 0;
            }
            else
            {
                printf("valeur validée : "); // [JEAN] -> Ca complique ton code, reste simple (même si l'idée est bien pensée pour la console Windows)
                printf("%f \n", val_util[i]);

                somme = somme + val_util[i];
                val_tab_ok = 1;
            }
        }

        if(val_tab_ok == 1)
        {
            moyenne = somme / nb_val;
            printf("moyenne = %f \n \n", moyenne);
        }
    }

    printf("fin du programme\n");
    return 0;
}
/*====================================================================================*/
