#include "header.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ch,found = 0;
     creeprofile();
     found = 1;
     if(!found)
     {
        printf("again cree profile");
     }

    do
    {
        printf("\033[32m""\n======= MENU =======\n""\033[0m");
        printf("1.  Gestion du profil client\n");
        printf("2.  Gestion du solde virtuel\n");
        printf("3.  Consultation des produits\n");
        printf("4.  Effectuer un achat\n");
        printf("5.  Mes statistiques\n");
        printf("0.  Quitter l'application\n");
        printf("Votre choix: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
        system("cls");
            int choix;
            printf("gestion du profil client : \n");
            printf("1. afficher profile \n");
            printf("2. modifier profile \n");
            printf("choix : ");
            scanf("%d", &choix);
            gererprofile(choix);
            break;
        case 2:
        system("cls");
            int choix2;
            printf("gestion du solde virtuel : \n");
            printf("1. affisher solde \n");
            printf("2. ajouter solde \n");
            printf("entre choix : ");
            scanf("%d", &choix2);
            gerer_sold(choix2);
            break;
        case 3:
        system("cls");
            int choix3;
            printf("\033[33m""\n==== Catalogue des Produits ====\n""\033[0m");
            printf("\033[32m""1. Affichage catalogue : Liste produits avec prix et stock\n""\033[0m");
            printf("2. Recherche produits : Par nom ou catégorie\n");
            printf("3. Tri des produits : Par prix (croissant/decroissant), par nom alphabetique\n");
            printf("4. Details produit : Affichage informations completes\n");
            printf("entre choix : ");
            scanf("%d",&choix3);
                Con_produits(choix3);
            break;
          case 4:
          system("cls");
          achat();
            break;
        case 5:
            statistiques();
            break;
        case 0:
            printf("Fin programme.\n");
            break;
        default:
            printf("Choix invalide!\n");
        }
    } while (ch != 0);

    return 0;
}
