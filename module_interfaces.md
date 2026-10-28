# Module and interface plan

The current implementation is kept in one `main.c` file to reduce integration complexity for an introductory C project. The logical responsibilities below define the agreed boundaries; functions can be split into `.c`/`.h` files later only if the team agrees and tests the change.

## Shared data structures
- `Product`: `id`, `name`, `category`, `price`, `quantity`, `low_stock_threshold`
- `Sale`: `sale_id`, `product_id`, `product_name`, `quantity`, `unit_price`, `total`, `date`

## Logical module ownership
- **Project lead / integration — Niladri Das Chanchal:** shared specification, menu and main integration, code review, README and report consistency.
- **Inventory management — Eashfee Ahmed:** add/list/search/update/restock behavior and product validation.
- **Sales management — Md. Jawad Muhib:** stock validation, sale total, sale record, stock reduction, sales history/summary.
- **Persistence and QA — Gourav Saha:** CSV load/save logic, test plan, regression checks, run/build instructions.

## Integration invariants
1. Product IDs are unique.
2. A sale is committed only after product, quantity, and available stock have been validated.
3. A rejected sale does not change stock or sales totals.
4. Inventory and sales summary use the same shared in-memory records.
5. Save/load behavior must be tested by the group before being described as verified.
