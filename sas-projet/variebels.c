#include "header.h"

int nbProduits = 10;
Client client[1];
int idnext = 1;

produit produits[PRODUCT_MAX] = {
    {1001, "iphone1", "Electronics", 25.99, 5, "Ergonomic"},
    {1002, "Water Bottle", "Home & Kitchen", 12.49, 13, "1L BPA-free"},
    {1003, "Yoga Mat", "Sports & Outdoors", 35.00, 7, "Non-slip yoga"},
    {1004, "Bluetooth Speaker", "Electronics", 45.89, 10, "Portable Bluetooth"},
    {1005, "LED Desk Lamp", "Office Supplies", 22.00, 9, "Adjustable"},
    {1006, "iphone2", "Office Supplies", 3.50, 5, "A5 spiral-bound"},
    {1007, "Running Shoes", "Sportswear", 79.99, 6, "Lightweight "},
    {1008, "Coffee Mug", "Home & Kitchen", 7.99, 9, "Ceramic coffee "},
    {1009, "Smartphone Stand", "Electronics", 9.99, 12, "Adjustable"},
    {1010, "iphone3", "Electronics", 5.49, 12, "1m USB-C "}
};
