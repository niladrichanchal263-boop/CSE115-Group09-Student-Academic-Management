# CSE115 Group 09 - Testing & QA Log
**Tester:** Gourav saha
## 1. Normal Tests
**Test 1.1: Add a Valid Product**
*  **Starting Data:** Empty inventory.
*  **Action:** Add ID '104', Name 'Marker', Price '20.00', Stock '50'.
*  **Expected Result:** Product is successfully added and appears in the inventory list.
*  **Actual Result:** _____________________________________
*  **Status:** [PASS/FAIL]

**Test 1.2: Valid Sale**
* **Starting Data:** ID '101'(pen) has 100 stock.
* **Action:** Sell 5 units of ID '101'.
* **Expected Result:** Total cost is calculated correctly (5 * 15.50 = 77.50). Stock for '101' drops to 95. Revenue increases by 77.50.
* **Actual Result:**_______________________________________
* **Status:**[PASS/FAIL]
