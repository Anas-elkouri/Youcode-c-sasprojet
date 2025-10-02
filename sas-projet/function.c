#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "header.h"
#define MAX 100
// cree profile
void creeprofile()
{
    printf("\033[32m"
           "\n====cree profile====\n"
           "\033[0m");

    printf("entre nom : ");
    scanf(" %[^\n]", client[0].nom);

    printf("entre prenom : ");
    scanf(" %[^\n]", client[0].prenom);
    client[0].id = idnext++;
    strcpy(client[0].email, client[0].prenom);
    strcat(client[0].email, ".");
    strcat(client[0].email, client[0].nom);
    strcat(client[0].email, "@gmail.com");
    printf("\033[32m""profile succes\n""\033[0m");
}
// gerer profile
void gererprofile(int choix)
{
    switch (choix)
    {
    case 1:
        printf("====afficher profile====\n");
        printf("id : %d\n", client[0].id);
        printf("nom : %s\n", client[0].nom);
        printf("prenom : %s\n", client[0].prenom);
        printf("email : %s\n", client[0].email);
        printf("solde : %.2f\n", client[0].sold);
        break;
    case 2:
        printf("====modifie profil====\n");
        printf("entre nom : ");
        scanf(" %[^\n]", client[0].nom);

        printf("entre prenom : ");
        scanf(" %[^\n]", client[0].prenom);

        client[0].id = idnext++;
        strcpy(client[0].email, client[0].prenom);
        strcat(client[0].email, ".");
        strcat(client[0].email, client[0].nom);
        strcat(client[0].email, "@gmail.com");
    default:
        printf("non choix ");
        break;
    }
}
// gerer sold
void gerer_sold(int choix2)
{
    switch (choix2)
    {
    case 1:
        printf("\033[32m""====afficher solde====\n""\033[0m");
        printf("solde : %.2f \n", client[0].sold);
        break;
    case 2:
        float montant;
        printf("====ajouter solde====\n");
        printf("entre montant ajouter : ");
        scanf("%f", &montant);
        if(montant<0){
            printf("\033[31m""no montant < 0 \n""\033[0m");
            return;
        }
        client[0].sold += montant;
        printf("sold : %.2f\n", client[0].sold);
    default:
        printf("non choix ");
        break;
    }
}
// Consultation_produits
void Con_produits(int choix3)
{
    switch (choix3)
    {
    case 1:
        printf("\033[32m""==== Liste des produits ====\n""\033[0m");
        for (int i = 0; i < nbProduits; i++)
        {
            printf("|id : %d|\n", produits[i].idProduit);
            printf("| nom :%s|\n", produits[i].nomproduit);
            printf("|prix : %.2f|\n", produits[i].prix);
            printf("|stock : %d|\n", produits[i].stock);
            printf("|categorie : %s|\n", produits[i].categorie);
            printf("|description : %s\n", produits[i].description);
            printf("--------------------------------------------------\n");
        }
        break;
    case 2:
        int found = 0;

        printf("\033[32m""==== recherche produits ====\n""\033[0m");
        char serch[MAX];
        printf("entre nom ou categorie : ");
        scanf(" %[^\n]", serch);
         for (int i = 0; serch[i] != '\0'; i++) {
        serch[i] = tolower(serch[i]);
    }
        for (int i = 0; i < nbProduits; i++)
        {
            if (strstr(produits[i].nomproduit, serch) != NULL || strstr(produits[i].categorie, serch) != NULL)
            {
                found = 1;
                printf("|id : %d|\n", produits[i].idProduit);
                printf("| nom :%s|\n", produits[i].nomproduit);
                printf("|prix : %.2f|\n", produits[i].prix);
                printf("|stock : %d|\n", produits[i].stock);
                printf("|categorie : %s|\n", produits[i].categorie);
                printf("|description : %s\n", produits[i].description);
                printf("--------------------------------------------------\n");
            }
        }
        if (!found)
        {
            printf("produit introuvable\n");
        }
        break;
    case 3:
        int tri;
        printf("===== tri produits =====\n");
        printf("1. tri par croissant prix \n");
        printf("2. tri par decroissant prix \n");
        printf("3. tri par nom alphabetique \n");
        printf("entre choix : ");
        scanf("%d", &tri);
        switch (tri)
        {
        case 1:
            babulsortprix1();
            for (int i = 0; i < nbProduits; i++)
            {
                printf("|id : %d|\n", produits[i].idProduit);
                printf("| nom :%s|\n", produits[i].nomproduit);
                printf("|prix : %.2f|\n", produits[i].prix);
                printf("|stock : %d|\n", produits[i].stock);
                printf("|categorie : %s|\n", produits[i].categorie);
                printf("|description : %s\n", produits[i].description);
                printf("--------------------------------------------------\n");
            }
            break;
        case 2:
            babulsortprix2();
            for (int i = 0; i < nbProduits; i++)
            {
                printf("|id : %d|\n", produits[i].idProduit);
                printf("| nom :%s|\n", produits[i].nomproduit);
                printf("|prix : %.2f|\n", produits[i].prix);
                printf("|stock : %d|\n", produits[i].stock);
                printf("|categorie : %s|\n", produits[i].categorie);
                printf("|description : %s\n", produits[i].description);
                printf("--------------------------------------------------\n");
            }
            break;
        case 3:
            babulsortnom();
            for (int i = 0; i < nbProduits; i++)
            {
                printf("|id : %d|\n", produits[i].idProduit);
                printf("| nom :%s|\n", produits[i].nomproduit);
                printf("|prix : %.2f|\n", produits[i].prix);
                printf("|stock : %d|\n", produits[i].stock);
                printf("|categorie : %s|\n", produits[i].categorie);
                printf("|description : %s\n", produits[i].description);
                printf("--------------------------------------------------\n");
            }
        }
        break;
    case 4:

        int idp;
        printf("\033[32m""==== details produit ====\n""\033[0m");
        printf("entre id produit : ");
        scanf("%d", &idp);

        int fond = 0;
        for (int i = 0; i < nbProduits; i++)
        {
            if (idp == produits[i].idProduit)
            {
                printf("|id : %d|\n", produits[i].idProduit);
                printf("| nom :%s|\n", produits[i].nomproduit);
                printf("|prix : %.2f|\n", produits[i].prix);
                printf("|stock : %d|\n", produits[i].stock);
                printf("|categorie : %s|\n", produits[i].categorie);
                printf("|description : %s\n", produits[i].description);
                printf("--------------------------------------------------\n");
                fond = 1;
                break;
            }
        }
        if (!fond)
        {
            printf("\033[32m""non produit\n""\033[0m");
        }
        break;
    default:
        printf("non choix ");
        break;
    }
}
// babul sort
void babulsortprix1()
{
    for (int i = 0; i < nbProduits - 1; i++)
    {
        for (int j = 0; j < nbProduits - i - 1; j++)
        {
            if (produits[j].prix > produits[j + 1].prix)
            {
                produit temp = produits[j];
                produits[j] = produits[j + 1];
                produits[j + 1] = temp;
            }
        }
    }
}
void babulsortprix2()
{
    for (int i = 0; i < nbProduits - 1; i++)
    {
        for (int j = 0; j < nbProduits - i - 1; j++)
        {
            if (produits[j].prix < produits[j + 1].prix)
            {
                produit temp = produits[j];
                produits[j] = produits[j + 1];
                produits[j + 1] = temp;
            }
        }
    }
}
void babulsortnom()
{
    for (int i = 0; i < nbProduits - 1; i++)
    {
        for (int j = 0; j < nbProduits - i - 1; j++)
        {
            if (strcasecmp(produits[j].nomproduit, produits[j + 1].nomproduit) > 0)
            {
                produit temp = produits[j];
                produits[j] = produits[j + 1];
                produits[j + 1] = temp;
            }
        }
    }
}

// Effectuer un achat

void achat()
{
    int fnd = 0;
    int idp;
    printf("\033[32m""==== achat produit ====\n""\033[0m");
    printf("entre id produit : ");
    scanf("%d", &idp);
    for (int i = 0; i < nbProduits; i++)
    {
        if (idp == produits[i].idProduit)
        {
            fnd = 1;
            printf("id : %d|\n", produits[i].idProduit);
            printf("| nom :%s|\n", produits[i].nomproduit);
            printf("|prix : %.2f|\n", produits[i].prix);
            printf("|stock : %d|\n", produits[i].stock);
            printf("|categorie : %s|\n", produits[i].categorie);
            printf("|description : %s\n", produits[i].description);
            printf("--------------------------------------------------\n");
            printf("\033[33m""==== confirmation achat ====\n""\033[0m");
            printf("the produit prix : %.2f \n", produits[i].prix);
            printf("your sold : %.2f \n", client[0].sold);
            printf("\033[32m""1. confirm achat \n""\033[0m");
            printf("\033[31m""0. annuler achat \n""\033[0m");
            break;
        }
    }
    if (!fnd)
    {
        printf("\031[32m""produit introuvable\n""\033[0m");
        return;
    }
    int confrm;
    printf("entre choix : ");
    scanf("%d", &confrm);
    switch (confrm)
    {
    case 1:
        acheterProduit();
        break;
    case 0:
        printf("\033[31m""achat annuler\n""\033[0m");
        break;

    default:
        printf("non choix ");
        break;
    }
}

void acheterProduit()
{
    int found = 0;
    int produitss;
    printf("entre again  id produit pour achat : ");
    scanf("%d", &produitss);
    for (int i = 0; i < nbProduits; i++)
    {
        if (produits[i].idProduit == produitss)
        {
            found = 1;
            int nbr;
            printf("entre nombre de produit a acheter : ");
            scanf("%d", &nbr);
            if (nbr <= produits[i].stock)
            {

                if (client[0].sold >= produits[i].prix)
                {
                    client[0].sold -= produits[i].prix * nbr;
                    produits[i].stock -= nbr;
                    produits[i].nbrs += nbr;
                    printf("\033[32m"" achat sucsuss\n achat de %s ""\033[m", produits[i].nomproduit);
                    printf("\033[31m""new sold : %.2f \n""\033[0m", client[0].sold);
                    printf("\033[32m""stock restant de %d \n""\033[0m", produits[i].nbrs);
                }
                else
                    printf("non solde\n");
            }
            else
            {
                printf("\033[31m""no stock.\n""\033[0m");
            }
        }
    }
    if (!found)
    {
        printf("\033[31m""Produit introuvable.\n""\033[0m");
    }
}
// Statistiques.
void statistiques()
{
    if (client[0].sold == 0)
    {
        printf("\033[33m""==== statistiques ====\n""\033[0m");
        printf("non sold.\n");
    }
    else
    {
        printf("\033[32m""==== statistiques ====\n""\033[0m");
        float total = 0.0;
        float mo = 0.0;
        if(produits[0].nbrs==0){
            printf("\033[33m""no achat \n""\033[0m");
            return;
        }
        for (int i = 0; i < nbProduits; i++)
        {
            if (produits[i].nbrs > 0)
            {
                mo = produits[i].prix * produits[i].nbrs;
                printf("\033[32m""produit : %s | nombre achete : %d | prix  : %.2f \n""\033[0m", produits[i].nomproduit, produits[i].nbrs, mo);
                total += produits[i].prix * produits[i].nbrs;
                printf("\033[32m""--------------------------------------------------\n""\033[0m");
            }
        }
        printf("\033[33m""total depense : %.2f \n""\033[0m", total);
    }
}

