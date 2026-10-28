/*
 * Inventory & Sales Manager
 * CSE115 - Group 09
 * Language: Standard C (C11-compatible; no external libraries)
 *
 * Members:
 * Niladri Das Chanchal, Eashfee Ahmed, Gourav Saha, Md. Jawad Muhib
 *
 * Build: gcc -std=c11 -Wall -Wextra -pedantic main.c -o inventory_manager
 * Run:   ./inventory_manager       (Windows: inventory_manager.exe)
 *
 * Data files are stored in the current working directory:
 * inventory.csv and sales.csv
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define MAX_PRODUCTS 500
#define MAX_SALES 2000
#define NAME_LEN 80
#define CATEGORY_LEN 50
#define DATE_LEN 20
#define INVENTORY_FILE "inventory.csv"
#define SALES_FILE "sales.csv"

typedef struct {
    int id;
    char name[NAME_LEN];
    char category[CATEGORY_LEN];
    double price;
    int quantity;
    int low_stock_threshold;
} Product;

typedef struct {
    int sale_id;
    int product_id;
    char product_name[NAME_LEN];
    int quantity;
    double unit_price;
    double total;
    char date[DATE_LEN];
} Sale;

static Product products[MAX_PRODUCTS];
static Sale sales[MAX_SALES];
static int product_count = 0;
static int sale_count = 0;
static int next_sale_id = 1;

static void trim_newline(char *s) {
    size_t n = strlen(s);
    while (n > 0 && (s[n - 1] == '\n' || s[n - 1] == '\r')) {
        s[--n] = '\0';
    }
}

static void read_line(const char *prompt, char *buffer, size_t size) {
    int ch;
    printf("%s", prompt);
    if (fgets(buffer, (int)size, stdin) == NULL) {
        buffer[0] = '\0';
        return;
    }
    if (strchr(buffer, '\n') == NULL) {
        while ((ch = getchar()) != '\n' && ch != EOF) { }
    }
    trim_newline(buffer);
}

static int read_int(const char *prompt, int min_value, int max_value) {
    char buffer[128], *end;
    long value;
    for (;;) {
        read_line(prompt, buffer, sizeof buffer);
        errno = 0;
        value = strtol(buffer, &end, 10);
        while (isspace((unsigned char)*end)) end++;
        if (buffer[0] != '\0' && *end == '\0' && errno == 0 &&
            value >= min_value && value <= max_value) {
            return (int)value;
        }
        printf("Enter a whole number from %d to %d.\n", min_value, max_value);
    }
}

static double read_double(const char *prompt, double min_value, double max_value) {
    char buffer[128], *end;
    double value;
    for (;;) {
        read_line(prompt, buffer, sizeof buffer);
        errno = 0;
        value = strtod(buffer, &end);
        while (isspace((unsigned char)*end)) end++;
        if (buffer[0] != '\0' && *end == '\0' && errno == 0 &&
            value >= min_value && value <= max_value) {
            return value;
        }
        printf("Enter a valid number from %.2f to %.2f.\n", min_value, max_value);
    }
}

static int find_product_index(int id) {
    int i;
    for (i = 0; i < product_count; i++) {
        if (products[i].id == id) return i;
    }
    return -1;
}

static void pause_for_enter(void) {
    char buffer[8];
    read_line("\nPress Enter to continue...", buffer, sizeof buffer);
}

static void print_header(void) {
    printf("\n%-8s %-24s %-18s %10s %8s %10s\n",
           "ID", "Product", "Category", "Price", "Stock", "Low-at");
    printf("--------------------------------------------------------------------------------\n");
}

static void display_product(const Product *p) {
    printf("%-8d %-24.24s %-18.18s %10.2f %8d %10d\n",
           p->id, p->name, p->category, p->price, p->quantity,
           p->low_stock_threshold);
}

static void list_products(void) {
    int i;
    if (product_count == 0) {
        printf("\nInventory is empty. Add a product first.\n");
        return;
    }
    print_header();
    for (i = 0; i < product_count; i++) display_product(&products[i]);
}

static void add_product(void) {
    Product p;
    char buffer[NAME_LEN];
    if (product_count >= MAX_PRODUCTS) {
        printf("Inventory capacity reached (%d products).\n", MAX_PRODUCTS);
        return;
    }
    printf("\n--- Add Product ---\n");
    p.id = read_int("Unique numeric product ID: ", 1, 999999999);
    if (find_product_index(p.id) >= 0) {
        printf("That ID already exists. Product was not added.\n");
        return;
    }
    read_line("Product name: ", buffer, sizeof buffer);
    if (buffer[0] == '\0' || strchr(buffer, ',') != NULL) {
        printf("Name cannot be empty or contain a comma. Product not added.\n");
        return;
    }
    snprintf(p.name, sizeof p.name, "%s", buffer);

    read_line("Category: ", buffer, sizeof buffer);
    if (buffer[0] == '\0' || strchr(buffer, ',') != NULL || strlen(buffer) >= CATEGORY_LEN) {
        printf("Category must be non-empty, shorter than %d characters, and contain no comma. Product not added.\n", CATEGORY_LEN);
        return;
    }
    memcpy(p.category, buffer, strlen(buffer) + 1);
    p.price = read_double("Unit price (0 or more): ", 0.0, 1000000000.0);
    p.quantity = read_int("Opening stock (0 or more): ", 0, 1000000000);
    p.low_stock_threshold = read_int("Low-stock warning threshold: ", 0, 1000000000);
    products[product_count++] = p;
    printf("Product added successfully.\n");
}

static void search_product(void) {
    int id, index;
    id = read_int("Enter product ID to search: ", 1, 999999999);
    index = find_product_index(id);
    if (index < 0) {
        printf("No product found with ID %d.\n", id);
        return;
    }
    print_header();
    display_product(&products[index]);
}

static void update_product(void) {
    int id, index, choice;
    char buffer[NAME_LEN];
    id = read_int("Enter product ID to update: ", 1, 999999999);
    index = find_product_index(id);
    if (index < 0) {
        printf("No product found with ID %d.\n", id);
        return;
    }
    printf("1. Change name\n2. Change category\n3. Change price\n4. Set stock quantity\n5. Change low-stock threshold\n");
    choice = read_int("Choose field: ", 1, 5);
    switch (choice) {
        case 1:
            read_line("New name: ", buffer, sizeof buffer);
            if (buffer[0] == '\0' || strchr(buffer, ',') != NULL) {
                printf("Invalid name; no change made.\n"); return;
            }
            snprintf(products[index].name, sizeof products[index].name, "%s", buffer);
            break;
        case 2:
            read_line("New category: ", buffer, sizeof buffer);
            if (buffer[0] == '\0' || strchr(buffer, ',') != NULL || strlen(buffer) >= CATEGORY_LEN) {
                printf("Invalid category (must be shorter than %d characters and contain no comma); no change made.\n", CATEGORY_LEN); return;
            }
            memcpy(products[index].category, buffer, strlen(buffer) + 1);
            break;
        case 3:
            products[index].price = read_double("New unit price: ", 0.0, 1000000000.0);
            break;
        case 4:
            products[index].quantity = read_int("New stock quantity: ", 0, 1000000000);
            break;
        case 5:
            products[index].low_stock_threshold = read_int("New warning threshold: ", 0, 1000000000);
            break;
    }
    printf("Product updated successfully.\n");
}

static void restock_product(void) {
    int id, index, amount;
    id = read_int("Product ID to restock: ", 1, 999999999);
    index = find_product_index(id);
    if (index < 0) {
        printf("Product not found.\n"); return;
    }
    amount = read_int("Quantity to add: ", 1, 1000000000);
    if (products[index].quantity > 1000000000 - amount) {
        printf("Stock limit would be exceeded; no change made.\n"); return;
    }
    products[index].quantity += amount;
    printf("Restocked. New stock: %d\n", products[index].quantity);
}

static void record_sale(void) {
    int id, index, qty;
    double total;
    Sale sale;
    char date[DATE_LEN];

    if (sale_count >= MAX_SALES) {
        printf("Sales history capacity reached (%d records).\n", MAX_SALES);
        return;
    }
    id = read_int("Product ID sold: ", 1, 999999999);
    index = find_product_index(id);
    if (index < 0) {
        printf("Product not found. Sale cancelled.\n"); return;
    }
    printf("Selected: %s | Price: %.2f | Available: %d\n",
           products[index].name, products[index].price, products[index].quantity);
    qty = read_int("Quantity sold: ", 1, 1000000000);
    if (qty > products[index].quantity) {
        printf("Insufficient stock. Sale cancelled; inventory unchanged.\n");
        return;
    }
    total = products[index].price * qty;
    if (total < 0.0) {
        printf("Invalid total. Sale cancelled.\n"); return;
    }
    read_line("Sale date (YYYY-MM-DD, or press Enter for 'unspecified'): ",
              date, sizeof date);
    if (date[0] == '\0') snprintf(date, sizeof date, "unspecified");
    if (strchr(date, ',') != NULL) {
        printf("Date cannot contain a comma. Sale cancelled.\n"); return;
    }

    /* Commit only after all validation: stock and sales remain consistent. */
    sale.sale_id = next_sale_id++;
    sale.product_id = products[index].id;
    snprintf(sale.product_name, sizeof sale.product_name, "%s", products[index].name);
    sale.quantity = qty;
    sale.unit_price = products[index].price;
    sale.total = total;
    snprintf(sale.date, sizeof sale.date, "%s", date);
    sales[sale_count++] = sale;
    products[index].quantity -= qty;

    printf("Sale recorded. Sale ID: %d | Total: %.2f | Remaining stock: %d\n",
           sale.sale_id, total, products[index].quantity);
}

static void show_low_stock(void) {
    int i, found = 0;
    printf("\n--- Low Stock Report ---\n");
    for (i = 0; i < product_count; i++) {
        if (products[i].quantity <= products[i].low_stock_threshold) {
            if (!found) print_header();
            display_product(&products[i]);
            found = 1;
        }
    }
    if (!found) printf("No products currently meet the low-stock warning condition.\n");
}

static void show_sales_history(void) {
    int i;
    if (sale_count == 0) {
        printf("\nNo sales have been recorded.\n"); return;
    }
    printf("\n%-8s %-8s %-22s %8s %12s %12s %-16s\n",
           "Sale ID", "Prod ID", "Product", "Qty", "Unit Price", "Total", "Date");
    printf("---------------------------------------------------------------------------------------------\n");
    for (i = 0; i < sale_count; i++) {
        printf("%-8d %-8d %-22.22s %8d %12.2f %12.2f %-16.16s\n",
               sales[i].sale_id, sales[i].product_id, sales[i].product_name,
               sales[i].quantity, sales[i].unit_price, sales[i].total, sales[i].date);
    }
}

static void sales_summary(void) {
    int i, units = 0;
    double revenue = 0.0;
    for (i = 0; i < sale_count; i++) {
        units += sales[i].quantity;
        revenue += sales[i].total;
    }
    printf("\n--- Sales Summary ---\n");
    printf("Number of recorded transactions: %d\n", sale_count);
    printf("Total units sold: %d\n", units);
    printf("Total recorded revenue: %.2f\n", revenue);
}

static int save_inventory(void) {
    FILE *fp = fopen(INVENTORY_FILE, "w");
    int i;
    if (fp == NULL) {
        perror("Could not open inventory file for writing");
        return 0;
    }
    fprintf(fp, "id,name,category,price,quantity,low_stock_threshold\n");
    for (i = 0; i < product_count; i++) {
        fprintf(fp, "%d,%s,%s,%.2f,%d,%d\n", products[i].id, products[i].name,
                products[i].category, products[i].price, products[i].quantity,
                products[i].low_stock_threshold);
    }
    if (fclose(fp) != 0) {
        perror("Error closing inventory file"); return 0;
    }
    return 1;
}

static int save_sales(void) {
    FILE *fp = fopen(SALES_FILE, "w");
    int i;
    if (fp == NULL) {
        perror("Could not open sales file for writing");
        return 0;
    }
    fprintf(fp, "sale_id,product_id,product_name,quantity,unit_price,total,date\n");
    for (i = 0; i < sale_count; i++) {
        fprintf(fp, "%d,%d,%s,%d,%.2f,%.2f,%s\n", sales[i].sale_id,
                sales[i].product_id, sales[i].product_name, sales[i].quantity,
                sales[i].unit_price, sales[i].total, sales[i].date);
    }
    if (fclose(fp) != 0) {
        perror("Error closing sales file"); return 0;
    }
    return 1;
}

static void save_all(void) {
    int inv_ok = save_inventory();
    int sales_ok = save_sales();
    if (inv_ok && sales_ok) printf("Inventory and sales saved successfully.\n");
    else printf("One or more files could not be saved. Check permissions and working directory.\n");
}

static void load_inventory(void) {
    FILE *fp = fopen(INVENTORY_FILE, "r");
    char line[512];
    if (fp == NULL) return; /* A first run is allowed to start with an empty inventory. */
    if (fgets(line, sizeof line, fp) == NULL) { fclose(fp); return; } /* header */
    while (fgets(line, sizeof line, fp) != NULL && product_count < MAX_PRODUCTS) {
        Product p;
        char *token;
        trim_newline(line);
        token = strtok(line, ","); if (!token) continue; p.id = atoi(token);
        token = strtok(NULL, ","); if (!token) continue; snprintf(p.name, sizeof p.name, "%s", token);
        token = strtok(NULL, ","); if (!token) continue; snprintf(p.category, sizeof p.category, "%s", token);
        token = strtok(NULL, ","); if (!token) continue; p.price = atof(token);
        token = strtok(NULL, ","); if (!token) continue; p.quantity = atoi(token);
        token = strtok(NULL, ","); if (!token) continue; p.low_stock_threshold = atoi(token);
        if (p.id > 0 && p.price >= 0 && p.quantity >= 0 &&
            p.low_stock_threshold >= 0 && find_product_index(p.id) < 0) {
            products[product_count++] = p;
        }
    }
    fclose(fp);
}

static void load_sales(void) {
    FILE *fp = fopen(SALES_FILE, "r");
    char line[512];
    if (fp == NULL) return;
    if (fgets(line, sizeof line, fp) == NULL) { fclose(fp); return; }
    while (fgets(line, sizeof line, fp) != NULL && sale_count < MAX_SALES) {
        Sale s;
        char *token;
        trim_newline(line);
        token = strtok(line, ","); if (!token) continue; s.sale_id = atoi(token);
        token = strtok(NULL, ","); if (!token) continue; s.product_id = atoi(token);
        token = strtok(NULL, ","); if (!token) continue; snprintf(s.product_name, sizeof s.product_name, "%s", token);
        token = strtok(NULL, ","); if (!token) continue; s.quantity = atoi(token);
        token = strtok(NULL, ","); if (!token) continue; s.unit_price = atof(token);
        token = strtok(NULL, ","); if (!token) continue; s.total = atof(token);
        token = strtok(NULL, ","); if (!token) continue; snprintf(s.date, sizeof s.date, "%s", token);
        if (s.sale_id > 0 && s.product_id > 0 && s.quantity > 0 &&
            s.unit_price >= 0 && s.total >= 0) {
            sales[sale_count++] = s;
            if (s.sale_id >= next_sale_id) next_sale_id = s.sale_id + 1;
        }
    }
    fclose(fp);
}

static void show_menu(void) {
    printf("\n========================================\n");
    printf("       INVENTORY & SALES MANAGER\n");
    printf("              CSE115 | Group 09\n");
    printf("========================================\n");
    printf("1. Add product\n");
    printf("2. Display inventory\n");
    printf("3. Search product by ID\n");
    printf("4. Update product details/stock\n");
    printf("5. Restock product\n");
    printf("6. Record sale\n");
    printf("7. View sales history\n");
    printf("8. Sales summary\n");
    printf("9. Low-stock report\n");
    printf("10. Save data now\n");
    printf("0. Save and exit\n");
}

int main(void) {
    int choice;
    load_inventory();
    load_sales();
    printf("Loaded %d product(s) and %d sale record(s).\n", product_count, sale_count);

    for (;;) {
        show_menu();
        choice = read_int("Select an option: ", 0, 10);
        switch (choice) {
            case 1: add_product(); break;
            case 2: list_products(); break;
            case 3: search_product(); break;
            case 4: update_product(); break;
            case 5: restock_product(); break;
            case 6: record_sale(); break;
            case 7: show_sales_history(); break;
            case 8: sales_summary(); break;
            case 9: show_low_stock(); break;
            case 10: save_all(); break;
            case 0:
                save_all();
                printf("Goodbye.\n");
                return 0;
            default: printf("Invalid menu option.\n"); break;
        }
        pause_for_enter();
    }
}
