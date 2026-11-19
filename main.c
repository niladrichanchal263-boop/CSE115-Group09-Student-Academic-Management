/*
 * Inventory & Sales Manager — CSE115 Group 09
 * Current stage: main menu and placeholder module navigation.
 */
#include <stdio.h>

void mainMenu(void) {
    printf("\n========================================\n");
    printf("       INVENTORY & SALES SYSTEM\n");
    printf("========================================\n");
    printf("1. Inventory Management\n");
    printf("2. Sales Management\n");
    printf("3. View Sales History\n");
    printf("4. View Total Revenue\n");
    printf("5. Exit\n");
}

/* Integration blueprint: connect these calls after teammates provide modules. */
int DummyMod(void) {
    int choice;
    while (1) {
        mainMenu();
        printf("\nEnter your choice: ");
        if (scanf("%d", &choice) != 1) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) { }
            printf("Invalid input. Enter a number from 1 to 5.\n");
            continue;
        }
        switch (choice) {
            case 1: /* inventoryMenu(); */
                printf("Inventory module is not connected yet.\n"); break;
            case 2: /* salesMenu(); */
                printf("Sales module is not connected yet.\n"); break;
            case 3: /* displaySales(); */
                printf("Sales history module is not connected yet.\n"); break;
            case 4: /* totalRevenue(); */
                printf("Revenue module is not connected yet.\n"); break;
            case 5:
                printf("Exiting program...\n"); return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

int main(void) {
    int choice;
    while (1) {
        mainMenu();
        printf("\nEnter your choice: ");
        if (scanf("%d", &choice) != 1) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) { }
            printf("Invalid input. Enter a number from 1 to 5.\n");
            continue;
        }
        switch (choice) {
            case 1: printf("Inventory Management selected.\n"); break;
            case 2: printf("Sales Management selected.\n"); break;
            case 3: printf("Sales History selected.\n"); break;
            case 4: printf("Total Revenue selected.\n"); break;
            case 5: printf("Exiting program...\n"); return 0;
            default: printf("Invalid choice. Try again.\n");
        }
    }
}
