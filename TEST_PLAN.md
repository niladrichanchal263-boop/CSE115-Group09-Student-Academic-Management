# CSE115 Group 09 - Testing & QA Log
**Tester:** Gourav saha

## 1. Normal Tests
### Test 1.1: Add a Valid Product
*  **Starting Data:** Baseline 'products.txt' loaded ('101', '102', '103').
*  **Action:** Add ID '104', Name 'Marker', Price '20.00', Stock '50'.
*  **Expected Result:** Product '104' is successfully added and appears in the inventory list.
*  **Actual Result:** _______________________________________
*  **Status:** [PASS / FAIL]

### Test 1.2: Valid Sale
* **Starting Data:** ID '101' ('pen', Price '15.50') has '100' stock.
* **Action:** Sell '5' units of ID '101'.
* **Expected Result:** Total cost is calculated correctly ('5 * 15.50 = 77.50'). Stock for '101' drops to '95'. Revenue increases by '77.50'.
* **Actual Result:**_________________________________________
* **Status:**[PASS / FAIL]

### Test 1.3: Search & Restock Product
* **Starting Data:** Id '103' ('Pencil', Price '10.00', Stock '200').
* **Action:** Search for ID '103', then restock by '50' units.
* **Expected Result:** Product '103' is found and displayed; stock updates from '200' to '250'.
* **Actual Result:**__________________________________________
* **Status:**[PASS / FAIL]

## 2. Invalid Tests

### Test 2.1: Reject Duplicate Product ID
* **Starting Data:** ID '101' ('Pen') already exists in inventory.
* **Action:** Try adding a new product with duplicate ID '101'.
* **Expected Result:** Rejected with a duplicate ID error message; original '101' record stays unchanged.
* **Actual Result:**____________________________________________
* **Status:**[PASS / FAIL]

### Test 2.2: Reject Negative Price or Stock
* **Starting Data:** Active inventory menu.
* **Action:** Try adding ID '105'with Price '-10.00' or Stock '-5'.
* **Expected Result:** Input is rejected with a validation message; inventory count remains unchanged.
* **Actual Result:**___________________________________________
* **Status:** [PASS / FAIL]

### Test 2.3: Reject Unknown ID & Invalid Sale Quantity
* **Starting Data:** ID '101' has '95' stock; total revenue is '77.50'.
* **Action:** Try selling unknown ID '999', '0' units of ID '101', and '-2' units of ID '101'.
* **Expected Result:** All three sales are rejected; ID '101', and stock stays '95' and revenue stays '77.50'.
* **Actual Result:**_____________________________________________
* **Status:**[PASS / FAIL]

### Test 2.4: Non-Numeric Menu Input
* **Starting Data:** Main menu prompt is active.
* **Action:** Type letters ('abc') instead of a menu number.
* **Expected Result:** Program displays an invalid input message and re-prompts cleanly without an infinite loop or crash.
* **Actual Result:**________________________________________
* **Status:**[PASS / FAIL]


