# Project Update Report — CSE115 Group 09

**Project:** Inventory & Sales Manager: A Menu-Driven Inventory and Sales Tracking System in C

**Team:** Niladri Das Chanchal; Eashfee Ahmed; Gourav Saha; Md. Jawad Muhib.

**Project objective:** The project aims to provide a small, menu-driven C application for maintaining product records, controlling stock, recording sales, and presenting basic summaries. It is designed as an introductory programming project and uses arrays, structures, functions, input validation, calculations, and file handling.

# Scope and planned functions

**Inventory:** Add products with unique IDs; display all products; search by ID; update product details and stock; restock products; and identify products at or below a low-stock threshold.

**Sales:** Record a sale only when the product exists and sufficient stock is available; calculate the transaction total; reduce stock after a valid sale; and show sales history and a summary of transactions, units sold, and recorded revenue.

**Persistence:** Save and reload product and sales records using simple CSV files. The current design stores `inventory.csv` and `sales.csv` in the program's working directory.

**Limitations:** The application is single-user, uses fixed in-memory capacity, and does not include authentication, a database, or advanced tax/discount processing. CSV fields cannot contain commas.

# Work allocation and integration

**Niladri Das Chanchal — Project Lead & Integration:** Coordinate the shared specification, integrate the menu and program flow, review code and documents, and ensure that the repository is consistent.

**Eashfee Ahmed — Inventory Management:** Own the inventory workflows: adding, listing, searching, updating, restocking, and validating product data.

**Md. Jawad Muhib — Sales Management:** Own sales validation, transaction totals, sale history, stock deduction, and sales summary behavior.

**Gourav Saha — Persistence, Testing & QA:** Own CSV save/load checks, test planning, edge-case review, build/run instructions, and regression checks.

**Integration rule:** The team must use one shared product list and common `Product` and `Sale` structures. Independent modules must not maintain competing copies of inventory.

# Progress and next steps

**Current deliverable:** A working first implementation, repository documentation, a manual test plan, and role-based learning guides have been prepared for team review. This report describes intended and implemented scope; it does not claim that all tests have already passed.

**Immediate next steps:** Each member should review their assigned code and explain the logic without reading the report. The team should compile the program, run the test plan, correct any discovered issues, and record actual results.

**GitHub workflow:** Use meaningful commits and clear messages that reflect real work. Keep `README.md`, `requirements.txt`, `data/`, `support/`, `others/`, `docs/`, and `tests/` organized. Upload presentation/report files before the instructor's stated deadline.

**Risks:** Potential risks include incompatible module assumptions, input edge cases, CSV parsing limitations, missed tests, and a demo that does not match the submitted code. Shared interfaces, early integration, and a rehearsed live run reduce these risks.

# Test plan snapshot

**Core checks:** Compile with GCC/Clang; add a product; reject duplicate IDs; search existing and missing IDs; update and restock stock; record a valid sale; reject an oversell without changing inventory; compare the sales history with the summary; and save/reload records.

**Status:** Tests are marked pending until the group executes them. The final report must include actual outcomes, dates, and tester names rather than assumed results.

# Conclusion

**Summary:** The project is scoped as a practical C application that connects product management, stock control, sales processing, reporting, and file handling. The next milestone is to verify the build and behavior, resolve defects, and prepare the update presentation and report for submission.