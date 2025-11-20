#include <iostream>
#include <map>
using namespace std;

// ===================================================================================
// ====================CLASSES========================================================
// ===================================================================================

class CatItem{
    public:
        std::string product_name;
        int quantity;
        double price;
        
        CatItem(){
            product_name = "";
            quantity = 0;
            price = 0.00;
        }
};

// ===================================================================================
// ====================CONSTANTS======================================================
// ===================================================================================

const double DISCOUNT = 0.15;

// ===================================================================================
// ====================TYPE DEFS======================================================
// ===================================================================================

typedef map<int, CatItem > catalogue; // for product catalogue

// ===================================================================================
// ====================FUNCTIONS======================================================
// ===================================================================================

/*
    This function creates a username from a person's name and surname

    input:  u_name = the name of the person
            u_surname = the surname of the person

    Returns: A username
*/
string userprompt() {
    string username,u_name, u_surname;
    cout << "Please enter your name: ";
    cin >> u_name;
    cout << "Please enter your surname: ";
    cin >> u_surname;
    cout << endl;

    username = u_name + " " + u_surname; // Concat the name and surname for a username
    return username;
}

/*
    This function creates a product to place a product into the catologue

    input:  name = the name of the product
            qty = the number of products
            price = the price of the product

    Returns: A class representing a catalogue item
*/
CatItem createProduct(string name, double price, int qty = 0){
    CatItem item;
    item.product_name = name; 
    item.quantity = qty; 
    item.price = price;

    return item;
}

/*
    This function populates the gadget catologue

    Returns: A catologue
*/
catalogue loadCatalogue(){
    catalogue productCatalogue;
    // Adding products to the catalogue dictionary
    productCatalogue[1] = createProduct("Wireless Mouse", 150.00);
    productCatalogue[2] = createProduct("Bluetooth Speaker", 250.00);
    productCatalogue[3] = createProduct("USB Flash Drive", 100.00);
    productCatalogue[4] = createProduct("Gaming Keyboard", 500.00);
    productCatalogue[5] = createProduct("Noise-Cancelling Headphones", 750.00);
    productCatalogue[6] = createProduct("Smartwatch", 1200.00);
    productCatalogue[7] = createProduct("External Hard Drive", 1000.00);
    productCatalogue[8] = createProduct("Portable Charger", 300.00);

    return productCatalogue;
}

/*
    This function displays the gadget catologue

    Returns: A catologue
*/
void displayCatalogue(catalogue productCatalogue){
    // Printing the product dictionary
    cout << "Catalogue:\n\n";
    for (int i = 1; i < productCatalogue.size() + 1; i++)//Loop through the dicionary until it the last value then stops
        cout << i << ". " 
        << productCatalogue[i].product_name 
        << " - R" << productCatalogue[i].price << endl; // Example "1. Wireless Mouse - R150"
}

/*
    This function allows the user to select in the catologue
*/
void selectProducts(string username,catalogue productCatalogue) {
    bool stop = false; // Condition to stop the loop
    int total_qty = 0, selected_index = 0, selected_qty = 0;
    double total = 0.00;

    while (stop == false) {
        cout << "\nPlease select a product (1-8), enter 0 to stop adding products: ";
        cin >> selected_index; 

        // Break the loop if the user types 0 (stop adding products)
        if (selected_index == 0) {
            stop = true;
            break;
        }

        // Checks if the product number exists
        if (selected_index >= (productCatalogue.size() + 1)) {
            cout << "\t\nInvalid product number. Try again.\n";
            continue;
        }
        
        // Check if the user can add more products
        int maxCanAdd = 10 - total_qty;
        if (maxCanAdd == 0) {
            cout << "\t\nYou have already reached the maximum of 10 products.\n";
            break;
        }

        // Enter the amount of product to add to cart
        cout << "\t\nPlease enter quantity for " << productCatalogue[selected_index].product_name 
        << " (You can add up to " << maxCanAdd << "): ";
        cin >> selected_qty;

        // Check if the current amount the user wants to add is more than what is available
        if (selected_qty > maxCanAdd) {
            cout << "\t\nToo many products, you can only add " << maxCanAdd << " more.\n";
            continue;
        }

        // Add quantity to cart (sums the qty if the user selects the same product twice)
        productCatalogue[selected_index].quantity += selected_qty;
        total_qty += selected_qty;

        if (total_qty == 10) {
            cout << "\t\nYou have reached the maximum of 10 products.\n";
            stop = true;
        }

        total += (selected_qty*productCatalogue[selected_index].price);
    }

    // Display this if the user has added products

    // Cart
    if (total_qty > 0){
        cout << "=============================="
        << "\nCart for: " << username << endl;
        for (int i = 1; i <= productCatalogue.size(); i++) {
            if (productCatalogue[i].quantity > 0) {  // only show products that were selected
                cout << "\n"
                << "\t" << "Product Name: " << productCatalogue[i].product_name << endl
                << "\t" << "Quantity: " << productCatalogue[i].quantity << endl
                << "\t" << "Cost: R" << (productCatalogue[i].quantity*productCatalogue[i].price) << "\n";
            }
        }
    
        // Check for discount and display total
        if (total > 2000.00){
            cout << "\nDiscount: " << (DISCOUNT*100) << "%" << endl
            << "Subtotal: R" << total << endl            
            << "Grand total: R" << (total*(1 - DISCOUNT)) << endl
            << "=====================";
        }

        // If there is no discount
        else {
            cout << "\nGrand total: R" << total << endl
            << "=====================";
        }
        }   
    
    // If cart is empty
    else{
        cout << "==============================" 
        << "\nYou have no products in your cart.\n"
        << "==============================";        
    }
}

/* 
    Main program flow:
    1. Prompt user for details
    2. Display product catalogue
    3. Let user select up to 10 items
    4. Calculate total and apply discount if applicable
    5. Display a summary of their order

    Example output:
    ==============================
    Cart for: Arthur Morgan

            Product Name: Wireless Mouse
            Quantity: 3
            Cost: R450

            Product Name: Gaming Keyboard
            Quantity: 7
            Cost: R3500

    Discount: 15%
    Subtotal: R3950
    Grand total: R3357.5
    ==============================
*/
int main() {
    string username;
    catalogue productCatalogue;
    
    username = userprompt();// prompts the user for their name and surname then creates a username for the cart
    productCatalogue = loadCatalogue(); // populate and display catalogue
    
    displayCatalogue(productCatalogue);
    selectProducts(username,productCatalogue);    // handles product selection

    return 0;
}
