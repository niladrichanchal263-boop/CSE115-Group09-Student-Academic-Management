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

    
