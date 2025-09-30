#ifndef HEADER_H
#define HEADER_H
#define MAX 100
#define MAX 100
#define CLTENT_MAX 1
#define PRODUCT_MAX 10

typedef struct
{
    int id;
    char nom[MAX];
    char prenom[MAX];
    char email[MAX];
    float sold;
}Client;

typedef struct
{
    int idProduit;
    char nomproduit[MAX];
    char prenomproduit[MAX];
    char categorie[MAX];
    float  prix;
    float stock;
    char description[MAX];
}produit_max;

produit_max produit[PRODUCT_MAX] = {
    {1001, "Wireless Mouse", "Electronics", 25.99, 5, "Ergonomic wireless mouse with USB dongle"},
    {1002, "Water Bottle", "Home & Kitchen", 12.49, 13, "1L BPA-free insulated water bottle"},
    {1003, "Yoga Mat", "Sports & Outdoors", 35.00, 7, "Non-slip yoga mat with carry strap"},
    {1004, "Bluetooth Speaker", "Electronics", 45.89, 10, "Portable Bluetooth speaker with bass"},
    {1005, "LED Desk Lamp", "Office Supplies", 22.00, 9, "Adjustable LED lamp with USB charging"},
    {1006, "Notebook", "Office Supplies", 3.50, 5, "A5 spiral-bound lined notebook"},
    {1007, "Running Shoes", "Sportswear", 79.99, 6, "Lightweight running shoes for men"},
    {1008, "Coffee Mug", "Home & Kitchen", 7.99, 9, "Ceramic coffee mug, 350ml"},
    {1009, "Smartphone Stand", "Electronics", 9.99, 12, "Adjustable mobile phone holder"},
    {1010, "USB-C Cable", "Electronics", 5.49, 12, "1m USB-C charging/data cable"},
}



#endif