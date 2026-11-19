# Test Plan — Current Main Menu Stage

## Scope
This plan covers the current menu framework only. Inventory, sales, and persistence
tests are for later integration and cannot yet be considered executed.

## Build check
```bash
gcc -std=c11 -Wall -Wextra -pedantic main.c -o inventory_manager
```
Record compiler output and environment after running the command.

## Main menu tests
| ID | Input/action | Expected result | Status |
|---|---|---|---|
| M01 | Start program | Main menu appears | Pending |
| M02 | Enter 1 | Inventory placeholder appears; menu repeats | Pending |
| M03 | Enter 2 | Sales placeholder appears; menu repeats | Pending |
| M04 | Enter 3 | Sales history placeholder appears; menu repeats | Pending |
| M05 | Enter 4 | Revenue placeholder appears; menu repeats | Pending |
| M06 | Enter 5 | Exit message appears and program terminates | Pending |
| M07 | Enter 0 or 9 | Invalid-choice message appears; menu repeats | Pending |
| M08 | Enter a letter | Invalid-input message appears; program continues | Pending |

## Later integration tests
After module connections, test duplicate product IDs, search, update, restock,
successful sale, oversell rejection, revenue/history consistency, and save/reload.

Do not mark a test passed without observing the expected result.
