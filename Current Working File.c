/*
Current Task:

- Displaying the main menu
- Taking user input
- Using switch to process choices
- Keeping the menu running using a loop
- Handling invalid choices
- Exiting the program properly
*/

/*
Main Menu:

1. Inventory Management
2. Sales Management
3. View Sales History
4. View Total Revenue
5. Exit
*/

#include <stdio.h>

void mainMenu(){
    // All options
    printf("\n========================================\n");
    printf(" INVENTORY & SALES SYSTEM\n");
    printf("========================================\n");
    printf("1. Inventory Management\n");
    printf("2. Sales Management\n");
    printf("3. View Sales History\n");
    printf("4. View Total Revenue\n");
    printf("5. Exit\n");
}

int main() {
    int choice;

    // Infinite loop to keep showing the menu
    while (1) {
        mainMenu(); // Display menu

        // Take user input for choice
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        // Switch-case to process the selected option
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

// Dummy program to test using dummy modules

// Dummy program to test module navigation

int DummyMod() {
    int choice;

    while (1) {
        mainMenu();

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

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
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}

