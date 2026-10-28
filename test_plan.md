# Test plan

Run these tests on the same compiled build and record the actual result/date/tester before final submission. Do not mark a test as passed until it has been executed.

## Build checks
- Compile with `gcc -std=c11 -Wall -Wextra -pedantic main.c -o inventory_manager`.
- Resolve all warnings that the team can explain; retain the compiler output in the team's working notes if useful.

## Functional checks
1. Add a valid product.
2. Try to add a duplicate ID; the second record must be rejected.
3. Display all products.
4. Search for an existing ID and a nonexistent ID.
5. Change a product's price and stock.
6. Restock a valid product.
7. Record a sale that is within stock; stock must decrease by the sale quantity.
8. Attempt a sale exceeding stock; stock and sales history must remain unchanged.
9. Attempt a sale for an unknown product ID; no sale should be recorded.
10. Check sales history and compare its total with the summary.
11. Set stock at or below the threshold and check the low-stock report.
12. Save and exit, restart, and check that records load.
13. Try non-numeric input for a numeric menu prompt.
14. Try empty product name/category and comma-containing fields.
15. Try saving in a location without write permission, if safely testable.

## Results table
| Test ID | Expected result | Actual result | Tester/date |
|---|---|---|---|
| T01 | Valid product is added | To be completed by team | Pending |
| T02 | Duplicate ID is rejected | To be completed by team | Pending |
| T03 | Successful sale reduces stock | To be completed by team | Pending |
| T04 | Oversell is rejected without mutation | To be completed by team | Pending |
| T05 | Save/reload restores records | To be completed by team | Pending |
