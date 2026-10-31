#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUCTS 100

// Shared struct agreed upon in vriables_format.txt
typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} Product;

// Function to extraxt data from the text file into memory 
int extractProductData(product inventory[], const char *filename){
    FILE *fp = fopen(filename, "r");

   if (fp == NULL) {
        printf("Notice: File '%s'not found. Starting with an empty inventory.\n", filename);
       return 0; 
    }
   
    int count = 0;

    // Read formatted data line by line until End of File or MAX_PRODUCTS is reached
   while ( count < MAX_PRODUCTS && fscanf(fp, "%d, %49[^,],%f,%d\n",
          &inventory[count].id,
          inventory[count].name,
          &inventory[count].price,
          &inventory[count].quantity) == 4) {
       count++;
    }
    
    fclose(fp);
    return count;
}

// Temporary main function to prove to the team that extraction works
int main() {
    Product inventory[MAX_PRODUCTS];
    int totalLoaded = extractProductData(inventory, "products.txt");

    
