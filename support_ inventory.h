#ifndef INVENTORY_H
#define INVENTORY_H

#include "extract_data.h"
#include <stdbool.h>

/* Core Inventory Functions (for Niladri to call from main.c)*/
int findProductById (const product products[] , int count, int targetId);
bool addproduct(product products[], int *count, int maxproducts);
void displayInventory(const product products[], int count);
void searchproduct(const product products[], int count);
bool updateproduct(product products[], int count);
bool restockproduct(product products[], int count);

/* Display helper */
void printproductrow(const Product *product);

#endif /* INVENTORY_H */
