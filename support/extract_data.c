#include "extract_data.h"
#include <ctype.h> -
#include <stdio.h>
#include <string.h>

void clearStdinBuffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
         /* discard */
    }
}

void trimWhitespace(char *str) {
    size_t len;
    size_t start = 0;

    if (str == NULL) {
        return;
    }

    len = strlen(str);
    while (len > 0 && isspace((unsigned char)str[len - 1])) {
        str[len - 1] = '\0';
        len--;
    }

    while (str[start] != '\0' && isspace((unsigned char)str[start])) {
        start++;
    }

    if (start > 0) {
        memmove(str, str + start, strlen(str + start) + 1);
    }
}
bool isSafeCsvString(const char *str) {
    size_t i;

    if (str == NULL || str[0] == '\0') {
        return false;
    }

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ',' || str[i] == '\n' || str[i] == '\r') {
            return false;
        }
    }
    return true;
}

bool isValidProductRecord(const Product *product) {
    if (product == NULL) {
        return false;
    }
    if (product->id <= 0 || !isSafeCsvString(product->name)) {
        return false;
    }
    if (product->price <= 0.0 || product->quantity < 0) {
        return false;
    }
    return true;
}

bool isValidSaleRecord(const Sale *sale) {
    if (sale == NULL) {
        return false;
    }
    if (sale->saleId <= 0 || sale->productId <= 0 || sale->quantitySold <= 0) {
        return false;
    }
    if (sale->unitPrice <= 0.0 || sale->totalAmount <= 0.0) {
        return false;
    }
    return true;
}

bool isDuplicateProductId(const Product products[], int currentCount, int id) {
    int i;
    for (i = 0; i < currentCount; i++) {
        if (products[i].id == id) {
            return true;
        }
    }
    return false;
}

bool parseProductLine(const char *line, Product *outProduct) {
    Product temp;
    char trailing;
    int matched;

    if (line == NULL || outProduct == NULL) {
        return false;
    }

    matched = sscanf(line, " %d, %49[^,], %lf, %d %c",
                     &temp.id, temp.name, &temp.price, &temp.quantity, &trailing);   
    if (matched != 4) {
        return false;
    }

    trimWhitespace(temp.name);
    if (!isValidProductRecord(&temp)) {
        return false;
    }

    *outProduct = temp;
    return true;
}

bool parseSaleLine(const char *line, Sale *outSale) {
    Sale temp;
    char trailing;
    int matched;

    if (line == NULL || outSale == NULL) {
        return false;
    }
        
   
