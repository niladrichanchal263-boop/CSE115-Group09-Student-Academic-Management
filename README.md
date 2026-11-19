# Inventory & Sales Manager — CSE115 Group 09

A planned menu-driven inventory and sales tracking application written in C.

## Team
- Niladri Das Chanchal — Project Lead & Integration
- Eashfee Ahmed — Inventory Management
- Md. Jawad Muhib — Sales Management
- Gourav Saha — Data Persistence, Testing & QA

## Current development status
The main-menu display function, repeating menu loop, switch-based selection, and
placeholder responses have been drafted. `DummyMod()` illustrates future module
navigation. Inventory, sales, and persistence are not yet connected in this version.
Shared structures and function interfaces still require team agreement.

## Build and run
```bash
gcc -std=c11 -Wall -Wextra -pedantic main.c -o inventory_manager
./inventory_manager
```
Windows (MinGW):
```powershell
gcc -std=c11 -Wall -Wextra -pedantic main.c -o inventory_manager.exe
.\inventory_manager.exe
```

## Integration workflow
1. Confirm shared structures and function prototypes.
2. Members develop assigned modules on separate branches.
3. Review pull requests for interface compatibility.
4. Integrate and compile the complete program.
5. Run tests and record observed results.
6. Update reports, presentation, and demo to match verified code.

Do not describe planned features as complete or tests as passed until verified.
