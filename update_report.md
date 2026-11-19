# Project Update Report — CSE115 Group 09

## Project
Inventory & Sales Manager: a menu-driven inventory and sales tracking system in C.

## Team responsibilities
- **Niladri Das Chanchal — Project Lead & Integration:** coordinate scope, maintain
  repository, agree shared structures/interfaces, develop main menu/navigation,
  review pull requests, integrate modules, resolve conflicts, test integration,
  proofread reports, and coordinate presentation/demo.
- **Eashfee Ahmed — Inventory Management:** add, display, search, update, and restock
  products; validate IDs and quantities; prevent duplicate IDs.
- **Md. Jawad Muhib — Sales Management:** validate sales, calculate totals, update
  stock after successful sales, record history, and calculate revenue.
- **Gourav Saha — Data Persistence, Testing & QA:** implement agreed saving/loading,
  help define record formats, test file errors, prepare test cases, check consistency,
  and document build/test results.

## Niladri's current coding progress
- Drafted `mainMenu()` to display the five main options.
- Drafted a `main()` loop that repeatedly displays the menu and reads a selection.
- Added switch cases for inventory, sales, sales history, revenue, and exit.
- Added placeholder responses because the other modules are not connected.
- Drafted `DummyMod()` as an integration blueprint.
- Identified shared structures and function interfaces as prerequisites for integration.

## Current status
This is an early menu-framework stage. The menu options currently display placeholder
messages. `DummyMod()` is a blueprint; its module calls remain commented out until
the corresponding functions and headers are supplied. This report does not claim
that the complete application is implemented, integrated, or tested.

## Next steps
1. Finalize Product and Sale structures with the team.
2. Confirm function names, parameters, and return types with module owners.
3. Develop inventory and sales submenu navigation.
4. Receive and review each member's module.
5. Integrate, compile, and test the complete application.
6. Update documentation and presentation from verified progress.

## Testing status
Main-menu tests and module acceptance tests remain pending until actually executed.
Record observed results, tester, and date; do not assume tests passed.
