#ifndef EXTRACT_DATA_H
#define EXTRACT_DATA_H

#include <stdbool.h>
#include <stddef.h>

#define MAX_PRODUCTS 100
#define MAX_SALES 500
#define MAX_NAME_LEN 50
#define MAX_LINE_LEN 256

#define PRODUCTS_FILE_PATH "data/products.txt"
#define SALES_FILE_PATH "data/sales.txt"

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    double price;
    int quantity;
} Product;

typedef struct {
    int saleId;
    int productId;
    int quantitySold;
    double unitPrice;
    double totalAmount;
} Sale;

int extractProductData(const char *filePath, Product products[], int maxProducts);
bool saveProductData(const char *filePath, const Product products[], int count);

int extractSalesData(const char *filePath, Sale sales[], int maxSales);
bool saveSalesData(const char *filePath, const Sale sales[], int count);

void trimWhitespace(char *str);
void clearStdinBuffer(void);
bool isSafeCsvString(const char *str);
bool isValidProductRecord(const Product *product);
bool isValidSaleRecord(const Sale *sale);
bool isDuplicateProductId(const Product products[], int currentCount, int id);
bool parseProductLine(const char *line, Product *outProduct);
bool parseSaleLine(const char *line, Sale *outSale);

#endif /* EXTRACT_DATA_H */
