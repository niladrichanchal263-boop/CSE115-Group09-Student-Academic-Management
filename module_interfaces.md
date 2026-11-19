# Module Interfaces — CSE115 Group 09

## Purpose
Proposed integration contract. Confirm every structure and signature with its owner
before implementation or merging.

## Proposed shared structures
```c
#define NAME_LEN 50
typedef struct {
    int id;
    char name[NAME_LEN];
    float price;
    int quantity;
} Product;

typedef struct {
    int productID;
    int quantity;
    float total;
} Sale;
```
The team must decide whether category, low-stock threshold, sale ID, unit price,
date, and other fields are required. All modules must share one inventory source.

## Proposed menu-level functions
```c
void inventoryMenu(void);
void salesMenu(void);
void displaySales(void);
void totalRevenue(void);
```

## Proposed inventory operations — confirm with Eashfee
```c
void addProduct(void);
void displayProducts(void);
int findProduct(int productID);
void updateProduct(void);
void restockProduct(void);
```

## Proposed sales operations — confirm with Jawad
```c
void sellProduct(void);
void displaySales(void);
float totalRevenue(void);
```
Avoid conflicting duplicate names/return types; finalize one signature per function.

## Proposed persistence operations — confirm with Gourav
```c
void loadData(void);
void saveData(void);
```

## Integration rules
1. Agree structures, names, parameters, and return types before integration.
2. Put shared declarations in agreed header files.
3. Keep each module's implementation with its assigned owner.
4. The main program owns top-level navigation; submenus own submenu navigation.
5. Successful sales update shared stock; rejected sales change neither stock nor sales.
6. Persistence uses the same agreed structures and fields.
7. Communicate interface changes before merging.

## Current status
- `mainMenu()` drafted.
- Main menu loop and placeholder responses drafted.
- `DummyMod()` integration blueprint drafted; module calls are commented out.
- Shared structures/prototypes are proposals, not finalized.
- Module connections remain pending.
