// Step 1 — Main menu loop

#include <stdio.h>

int main() {
    int choice;

    while (1) {
        printf("\n===============================\n");
        printf("   INVENTORY & SALES SYSTEM\n");
        printf("===============================\n");
        printf("1. Inventory Management\n");
        printf("2. Sales Management\n");
        printf("3. View Sales History\n");
        printf("4. View Total Revenue\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Inventory Management selected.\n");
                break;

            case 2:
                printf("Sales Management selected.\n");
                break;

            case 3:
                printf("Sales History selected.\n");
                break;

            case 4:
                printf("Total Revenue selected.\n");
                break;

            case 5:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

// Dummy Modules

int main() {
    int choice;

    while (1) {
        choice = mainMenu();

        switch (choice) {
            case 1:
                inventoryMenu();
                break;
            case 2:
                salesMenu();
                break;
            case 3:
                displaySales();
                break;
            case 4:
                totalRevenue();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
