# E-commerce Cart System 🛒
### BSc Information Technology (Network and Security Engineering) - Year 1
**Institution:** Eduvos | **Module:** Procedural Programming

## Overview
This application simulates the backend logic of an online shopping cart. It manages a product catalogue of electronic goods, handles user cart selections, and calculates totals with conditional logic for discounts.

## Features
* **Catalogue System:** Uses `std::map` to pair Product IDs with Item Objects.
* **Cart Logic:** * Inventory management (users cannot select invalid items).
    * Quantity caps (maximum 10 items per cart).
* **Dynamic User Profiles:** Generates usernames based on input.
* **Financial Logic:** Automatically applies a 15% discount for orders over R2000.

## Concepts Demonstrated
* **Classes & Objects:** Defining `CatItem` structure.
* **STL Maps:** Using dictionaries for efficient data lookup.
* **Typedefs:** Creating custom type definitions for code readability.
* **Complex Conditionals:** Handling discounts and inventory limits.

## How to Run
This is a standalone C++ file. You can compile it using G++, Clang, or MSVC.

**Using Terminal (G++):**
1.  Compile the code:
    ```bash
    g++ EcommerceCartSystem.cpp -o shop_system
    ```
2.  Run the application:
    ```bash
    ./shop_system
    ```
    *(On Windows, run `shop_system.exe`)*
