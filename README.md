# InventoryManagementSystem

Third assignment for Data Structures and Algorithms in C.

November 17, 2023

**1. Overview:**
   - The C project is an Inventory Management System that utilizes a linked list to store information about different parts in an inventory.
   - Users can add new parts, find parts and their quantities, update the quantity on hand, and display the entire inventory.

**2. Key Features:**

   - **Node Structure:**
     - Defines a `part` structure with fields for part number, name, quantity on hand, and a pointer to the next part.
     - Struct is named `part`.

   - **Insertion Operation:**
     - **Insert Part:**
       - Adds a new part to the inventory with specified part number, name, and quantity on hand.
       - Function: `insertPart(int num, char newName[], int numberOnHand, Part *head)`

   - **Search Operation:**
     - **Search Part:**
       - Searches for a part in the inventory by its part number.
       - Function: `search(int n, Part *list)`

   - **Update Operation:**
     - **Change Quantity:**
       - Updates the quantity on hand for a specific part.
       - Function: `changeQuantity(int n, int quantity, Part *list)`

   - **Sorting Operation:**
     - **Bubble Sort:**
       - Sorts the inventory based on part numbers using the bubble sort algorithm.
       - Function: `bubbleSort(Part *start)`

   - **Display Operation:**
     - **Print Inventory:**
       - Displays all parts in the inventory, including part number, name, and quantity on hand.
       - Function: `print(Part *head)`

   - **Menu-Driven Interface:**
     - Provides a user-friendly menu for selecting different operations.
     - Implemented using an infinite loop until the user chooses to exit.

   - **Dynamic Memory Allocation:**
     - Allocates memory dynamically for new parts during insertion operations.
     - Ensures proper memory deallocation during program termination.

**3. Usage:**
   - Users can interact with the program through the console, selecting options to manage the inventory.

**4. Input Validation:**
   - Ensures that only valid numerical and string inputs are accepted.
   - Provides appropriate feedback for incorrect input types.

**5. Error Handling:**
   - Handles scenarios such as part not found, empty inventory, and invalid inputs gracefully.
   - Prompts users with appropriate messages for better interaction.

**6. Continuous Execution:**
   - The program runs continuously until the user chooses to exit, allowing multiple inventory operations in a single run.

**7. Conclusion:**
   - The project serves as a basic Inventory Management System implemented in C.
   - It provides fundamental functionalities for adding, searching, updating, and displaying parts in an inventory.
   - The menu-driven interface enhances user experience and ease of interaction.
