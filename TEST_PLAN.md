# CSE115 Group 09 - Testing & QA Log
**Tester:** Gourav saha

## 1. Normal Tests
### Test 1.1: Add a Valid Product
*  **Starting Data:** Baseline 'products.txt' loaded ('101', '102', '103').
*  **Action:** Add ID '104', Name 'Marker', Price '20.00', Stock '50'.
*  **Expected Result:** Product '104' is successfully added and appears in the inventory list.
*  **Actual Result:** _____________________________________
*  **Status:** [PASS/FAIL]

### Test 1.2: Valid Sale
* **Starting Data:** ID '101' ('pen', Price '15.50') has '100' stock.
* **Action:** Sell '5' units of ID '101'.
* **Expected Result:** Total cost is calculated correctly ('5 * 15.50 = 77.50'). Stock for '101' drops to '95'. Revenue increases by '77.50'.
* **Actual Result:**_______________________________________
* **Status:**[PASS/FAIL]

### Test 1.3: Search & Restock Product
* **Starting Data:** Id '103' ('Pencil', Price '10.00', Stock '200').
* **Action:** Search for ID '103', then restock by '50' units.
* **Expected Result:** Product '103' is found and displayed; stock updates from '200' to '250'.
* **Actual Result:**________________________________________
* **Status:**[PASS/FAIL]
