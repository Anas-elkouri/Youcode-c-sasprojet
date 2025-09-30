#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include <windows.h>

int main()
{
    int ch;

    do{
        printf("\n======= MENU =======");
        printf("1.  Gestion du profil client\n");
        printf("2.  Gestion du solde virtuel\n");
        printf("3.  Consultation des produits\n");
        printf("4.  Effectuer un achat\n");
        printf("5.  Mes statistiques\n");
        printf("0.  Quitter l'application\n");

        switch (ch)
        {
        case 1:
        int choix;
        printf("1. Creation de profil : \n");
        printf("2. Modification du profil : Mise à jour nom et prénom : \n");
        printf("3. Consultation du profil : Affichage informations client + solde actuel : \n");
        printf("entre choix : ");
        scanf("%d",&choix);
        switch (choix)
        {
        case 1:
            break;
        
        default:
            break;
        }
            break;
        
        default:
            break;
        }
    }while (ch != 0);
    
}