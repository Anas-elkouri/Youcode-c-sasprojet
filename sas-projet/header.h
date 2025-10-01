#ifndef HEADER_H
#define HEADER_H
#define MAX 100
#define PRODUCT_MAX 10

typedef struct {
    int id;
    char nom[MAX];
    char prenom[MAX];
    char email[MAX];
    float sold;
} Client;

typedef struct {
    int idProduit;
    char nomproduit[MAX];
    char categorie[MAX];
    float prix;
    int stock;
    char description[MAX];
    int nbrs;
} produit;

extern produit produits[PRODUCT_MAX];
extern int nbProduits;
extern Client client[1];
extern int idnext;

void  creeprofile();
 void gererprofile(int choix);
 void Modificationprofile();
 void affisherprofile();
 void gerer_sold(int choix2);
 void Con_produits(int choix3);
 void babulsortprix1();
 void babulsortprix2();
 void babulsortnom();
 void achat();
 void acheterProduit();
 void statistiques();
void lowercase();

#endif
