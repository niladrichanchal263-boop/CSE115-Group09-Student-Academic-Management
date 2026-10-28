# 1. Introduction

**1.1 Background:** Small shops need a reliable way to track what products are available, how much stock remains, and how sales affect inventory. A simple console-based application can demonstrate the core logic behind such a workflow without requiring a database or a graphical interface.

**1.2 Project overview:** Inventory & Sales Manager is a menu-driven program written in C for the CSE115 Group 09 project. It manages product records, supports stock changes, records sales, creates basic reports, and saves information in CSV files.

**1.3 Problem statement:** Manual stock tracking can lead to duplicate product records, inaccurate quantities, and sales being recorded without enough stock. The program addresses these issues through unique product IDs, validation, stock checks, and a consistent record structure.

**1.4 Objectives:** The objectives are to practise fundamental C programming; keep a searchable product list; prevent duplicate product IDs; validate stock before a sale; calculate totals; show sales and low-stock summaries; and persist records between runs.

# 2. Scope and Requirements

**2.1 Functional requirements:** The program can add a product, display inventory, search by ID, update a product field, restock a product, record a sale, display sales history, calculate a sales summary, list low-stock products, save records, and exit after saving.

**2.2 Data requirements:** A product stores an ID, name, category, unit price, quantity, and low-stock threshold. A sale stores a sale ID, product ID, product name at the time of sale, quantity, unit price, total, and date string.

**2.3 Input rules:** IDs must be positive integers and unique for products. Quantities and thresholds must be non-negative; sale quantities must be positive. Prices must be non-negative. Empty names/categories and comma-containing product fields are rejected.

**2.4 Non-functional requirements:** The console interface should be understandable to a beginner, input errors should not crash the program, source code should compile using a standard C compiler, and the repository should include build instructions and test documentation.

**2.5 Out of scope:** The project does not provide user accounts, multi-user access, a database server, barcode scanning, payment processing, tax/discount rules, a graphical interface, or production-grade auditing.

# 3. Design and Architecture

**3.1 Program structure:** The current implementation keeps the program in `main.c` so that the introductory project remains easy to compile and review. Functions separate input handling, inventory operations, sales operations, reports, and file persistence.

**3.2 Product structure:** The `Product` structure groups the product ID, name, category, price, stock quantity, and low-stock threshold. An array of products is the shared inventory source for all operations.

**3.3 Sale structure:** The `Sale` structure captures the product identity and name, quantity, unit price, calculated total, and date text. The sales array supports a history view and summary calculations.

**3.4 Menu flow:** At startup the program attempts to load saved inventory and sales files. It then displays a menu, reads a validated option, invokes the corresponding operation, and returns to the menu. Choosing exit attempts to save both data sets before terminating.

**3.5 Integration principle:** All features use the same shared arrays and structures. This avoids duplicate inventories and makes the relationship between a recorded sale and the stock quantity explicit.

# 4. Implementation

**4.1 Inventory management:** Adding a product checks the capacity and ID uniqueness before storing a record. Product name and category must be non-empty and must not contain commas because the persistence format is simple CSV. Display and search functions show stored values; update functions modify a selected field; restocking adds a positive amount after checking the upper bound.

**4.2 Sales processing:** A sale begins by finding the product. The user enters a positive quantity, which is compared with available stock. If the requested quantity exceeds stock, the operation is cancelled without mutating stock or sales history. Otherwise the total is calculated, date text is collected, a sale record is appended, and stock is reduced.

**4.3 Reports:** The sales history displays each recorded transaction. The sales summary calculates transaction count, total units sold, and recorded revenue from the sales array. The low-stock report displays products whose quantity is less than or equal to the configured threshold.

**4.4 File handling:** The program uses `inventory.csv` and `sales.csv`. It writes a header and one record per line, and it attempts to load records at startup. If the files do not exist on a first run, the program begins with empty arrays. Files are written to the current working directory.

**4.5 Input validation:** Numeric input is parsed from a line rather than read directly with `scanf`, reducing common input-buffer problems. Range checks are applied to menu options, IDs, quantities, thresholds, and prices.

# 5. Testing and Verification Plan

**5.1 Test approach:** Testing should cover normal operations, invalid input, boundary values, consistency between inventory and sales, and persistence across program runs. The team should execute the test cases in `tests/manual_test_cases.csv` and record actual outcomes.

**5.2 Core scenarios:** Tests include adding a valid product; rejecting a duplicate ID; searching for existing and missing IDs; updating and restocking stock; recording a sale within stock; rejecting an oversell; checking revenue totals; triggering a low-stock warning; and saving/reloading data.

**5.3 Expected invariants:** A product ID must not be duplicated. A successful sale decreases stock by the sold quantity. A rejected sale does not change stock or the sales count. The sales summary should agree with the stored sale records. Saved data should be checked after restarting.

**5.4 Test status:** This report intentionally does not invent test outcomes. Test results, execution dates, and tester names must be completed by the team after running the submitted build.

# 6. Team Responsibilities and Workflow

**6.1 Niladri Das Chanchal — Project Lead & Integration:** Coordinate scope, maintain the shared interface, integrate the menu and modules, review changes, proofread documentation, and ensure the presentation reflects the final code.

**6.2 Eashfee Ahmed — Inventory Management:** Implement and explain product creation, listing, search, update, restocking, and validation. Demonstrate duplicate-ID rejection and stock changes.

**6.3 Md. Jawad Muhib — Sales Management:** Implement and explain sale validation, transaction totals, stock deduction, history, and summary. Demonstrate both a valid sale and an oversell rejection.

**6.4 Gourav Saha — Persistence, Testing & QA:** Implement/review file save and load, maintain the test plan, run regression checks, verify error cases, and document build/run steps.

**6.5 Collaboration:** All members should review the shared code, understand the overall program flow, communicate interface changes before merging, and make genuine commits for work actually performed.

# 7. Limitations, Risks and Future Improvements

**7.1 Current limitations:** The application has fixed capacities for products and sales, runs as a single-user console program, uses basic CSV parsing, and stores the date as text without validating calendar correctness. Product names and categories cannot contain commas.

**7.2 Risks:** Risks include inconsistent edits to shared structures, malformed manually edited CSV files, missed input edge cases, untested file permissions, and a presentation/demo that differs from the submitted code. Testing and clear ownership reduce but do not automatically eliminate these risks.

**7.3 Future improvements:** Possible future work includes splitting the program into multiple source/header files, stronger CSV parsing, date validation, more detailed reports, configurable file paths, safer file-update strategy, product deletion, and unit-test automation if allowed by the course.

**7.4 Security and reliability note:** This is an educational demonstration, not a production inventory or payment system. It has no authentication, encryption, concurrent access protection, or formal audit trail.

# 8. Conclusion and References

**8.1 Conclusion:** Inventory & Sales Manager combines inventory management, sales processing, reporting, and file handling in a single beginner-level C application. Its most important consistency rule is that a sale must be validated before stock is changed. The group should compile, execute, and document every test before presenting the project.

**8.2 References:** The team must add the exact external references, tutorial videos, and AI tools actually used to `support/REFERENCES.md`. No source should be listed unless it was used, and the members must be able to explain and take responsibility for submitted code.