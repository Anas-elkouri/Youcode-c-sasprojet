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
        printf("====afficher solde====\n");
        printf("solde : %.2f \n", client[0].sold);
        break;
    case 2:
        float montant;
        printf("====ajouter solde====\n");
        printf("entre montant ajouter : ");
        scanf("%f", &montant);
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
        printf("==== Liste des produits ====\n");
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

        printf("==== recherche produits ====\n");
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
        printf("==== details produit ====\n");
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
            printf("produit introuvable\n");
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
    printf("==== achat produit ====\n");
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
            printf("==== confirmation achat ====\n");
            printf("the produit prix : %.2f \n", produits[i].prix);
            printf("your sold : %.2f \n", client[0].sold);
            printf("1. confirm achat \n");
            printf("0. annuler achat \n");
            break;
        }
    }
    if (!fnd)
    {
        printf("produit introuvable\n");
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
        printf("achat annuler\n");
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
                    client[0].sold -= produits[i].prix;
                    produits[i].stock--;
                    produits[i].nbrs += nbr;
                    printf(" achat sucsuss\n achat de %s ", produits[i].nomproduit);
                    printf("new sold : %.2f \n", client[0].sold);
                    printf("stock restant de %d \n", produits[i].nbrs);
                }
                else
                    printf("non solde\n");
            }
            else
            {
                printf("no stock.\n");
            }
        }
    }
    if (!found)
    {
        printf("Produit introuvable.\n");
    }
}
// Statistiques.
void statistiques()
{
    if (client[0].sold == 0)
    {
        printf("==== statistiques ====\n");
        printf("vous n'avez pas encore effectue d'achat.\n");
    }
    else
    {
        printf("==== statistiques ====\n");
        float total = 0.0;
        for (int i = 0; i < nbProduits; i++)
        {
            if (produits[i].nbrs > 0)
            {
                printf("produit : %s | nombre achete : %d | prix  : %.2f \n", produits[i].nomproduit, produits[i].nbrs, produits[i].prix);
                total += produits[i].prix * produits[i].nbrs;
                printf("--------------------------------------------------\n");
            }
        }
        printf("total depense : %.2f \n", total);
    }
}
// void lowercase()
// {
//     for (int i = 0; i < nbProduits; i++) 
//     {
       
//         for (int j = 0; produits[i].nomproduit[j] != '\0'; j++) {
//             produits[i].nomproduit[j] = tolower(produits[i].nomproduit[j]);
//         }

    
//         for (int j = 0; produits[i].categorie[j] != '\0'; j++) {
//             produits[i].categorie[j] = tolower(produits[i].categorie[j]);
//         }
//     }
// }
