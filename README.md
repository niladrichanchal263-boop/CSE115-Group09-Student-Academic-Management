# Inventory & Sales Manager — CSE115 Group 09

A menu-driven inventory and sales tracking system written in standard C. The program supports product management, stock control, sales recording, simple reports, and CSV file persistence.

## Team
- Niladri Das Chanchal — Project Lead & Integration
- Eashfee Ahmed — Inventory Management
- Gourav Saha — Data Persistence, Testing & QA
- Md. Jawad Muhib — Sales Management

## Features
- Add products with unique numeric IDs
- List and search products
- Update product name, category, price, stock, and low-stock threshold
- Restock products
- Record sales after validating product and available stock
- Automatically reduce stock after a successful sale
- View sales history and sales summary
- Flag products at or below their low-stock threshold
- Load and save inventory and sales records in CSV files

## Requirements
- A C compiler that supports standard C (for example GCC or Clang)
- No third-party libraries are required

## Build and run

### Linux / macOS
```bash
gcc -std=c11 -Wall -Wextra -pedantic main.c -o inventory_manager
./inventory_manager
```

### Windows (MinGW GCC)
```powershell
gcc -std=c11 -Wall -Wextra -pedantic main.c -o inventory_manager.exe
.\inventory_manager.exe
```

Run the program from the repository root so that `inventory.csv` and `sales.csv` are created there. The application loads these files on startup if they exist and saves both on exit. A first run can start with empty files.

## Data files
- `inventory.csv` — product ID, name, category, unit price, stock quantity, low-stock threshold
- `sales.csv` — sale ID, product ID, product name at time of sale, quantity, unit price, total, date

CSV values currently must not contain commas. The program rejects commas in product names/categories and sale dates. Keep backups of data files before manually editing them.

## Suggested demo sequence
1. Start the program and add product ID `101`, name `Notebook`, category `Stationery`, price `80`, opening stock `10`, threshold `3`.
2. Display inventory and search for ID `101`.
3. Record a sale of 2 notebooks; verify stock drops from 10 to 8.
4. Attempt to sell 99 notebooks; verify the sale is rejected and stock remains 8.
5. Restock 5 notebooks; verify stock becomes 13.
6. View sales history, sales summary, and low-stock report.
7. Save and exit, then restart and verify records load.

## Known limitations
- Single-user, in-memory operation while running; no login or role system.
- Fixed maximum capacities are defined in `main.c`.
- CSV storage uses a simple comma-separated format and does not support commas inside fields.
- Date input is stored as entered; the program does not validate calendar correctness.
- This is an educational CSE115 project, not a production point-of-sale system.

## Project layout
```text
main.c
README.md
requirements.txt
data/
  README.md
support/
  test_plan.md
  module_interfaces.md
docs/
  update_report.md
  final_report.md
others/
  UPDATE_PRESENTATION.pptx
  UPDATE_REPORT.pdf
  FINAL_PRESENTATION.pptx
  FINAL_REPORT.pdf
  DEMO_SCRIPT.md
  PRESENTATION_CHECKLIST.md
tests/
  manual_test_cases.csv
```

## Academic integrity and citations
List any external sources, tutorial videos, or AI tools actually used in `support/REFERENCES.md` before final submission. Do not claim tests were run unless the team has run them. Make genuine commits that represent real work; do not fabricate commit history.
