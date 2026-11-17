#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUCTS 100

// Shared struct agreed upon in variables_format.txt
typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} Product;

// 1. Load data from the text file into memory
int extractProductData(Product inventory[], const char *filename) {
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Notice: File '%s' not found. Starting with an empty inventory.\n", filename);
        return 0;
    }

    int count = 0;

    // Read formatted data line by line until End of File or MAX_PRODUCTS is reached
    while (count < MAX_PRODUCTS && fscanf(fp, " %d,%49[^,],%f,%d",
           &inventory[count].id,
           inventory[count].name,
           &inventory[count].price,
           &inventory[count].quantity) == 4) {
        count++;
    }

    fclose(fp);
    return count;
}

// 2. Save updated product records back to the text file
int saveProductData(Product inventory[], int count, const char *filename) {
    FILE *fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Error: Could not open '%s' for saving.\n", filename);
        return 0;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d,%s,%.2f,%d\n",
                inventory[i].id,
                inventory[i].name,
                inventory[i].price,
                inventory[i].quantity);
    }

    if (ferror(fp)) {
        printf("Error: Failed while writing data to '%s'.\n", filename);
        fclose(fp);
        return 0;
    }

    fclose(fp);
    return 1;
}

// Standalone test driver to verify extraction and saving work
int main() {
    Product inventory[MAX_PRODUCTS];
    int totalLoaded = extractProductData(inventory, "products.txt");

    printf("\n--- Data Extraction Test ---\n");
    printf("Total products loaded: %d\n\n", totalLoaded);

    for (int i = 0; i < totalLoaded; i++) {
        printf("ID: %d | Name: %-10s | Price: %.2f | Stock: %d\n",
               inventory[i].id,
               inventory[i].name,
               inventory[i].price,
               inventory[i].quantity);
    }

    if (saveProductData(inventory, totalLoaded, "products.txt")) {
        printf("\nSave check passed: %d records written back to products.txt.\n", totalLoaded);
    }

    return 0;
}
