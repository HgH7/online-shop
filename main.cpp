#include <iostream>
#include <limits>
#include <string>
#include <algorithm> 

#include "./DS/products.h"
#include "./DS/customerAcc.h"
#include "./DS/cartSystem.h"
#include "./DS/orderHistory.h"
#include "./DS/deliveryqueue.h"

#include "./Algo/Search.h"
#include "./Algo/Sort.h"

using namespace std;

// ==========================
// FUNCTION PROTOTYPES
// ==========================
int getIntInput(const string& prompt, int min = INT_MIN, int max = INT_MAX);
double getDoubleInput(const string& prompt, double min = 0);
string getStringInput(const string& prompt, bool allowEmpty=false);

void seedProducts(ProductCatalog& catalog);
void browseProducts(ProductCatalog& catalog, ReturnStack& cart);
void viewCartCheckout(ReturnStack& cart, CustomerList& customers, OrderHistory& orderHistory, DeliveryQueue& deliveryQueue, int& orderCounter);
void viewProfile(CustomerList& customers, OrderHistory& orderHistory);
void adminPanel(ProductCatalog& catalog, DeliveryQueue& deliveryQueue);
void runShopSystem();

// ==========================
// MAIN FUNCTION
// ==========================
int main() {
    cout << "======================================\n";
    cout << "    🛒 WELCOME TO THE NILE STORE 🛒\n";
    cout << "======================================\n";
    runShopSystem();

    cout << "\nThank you for shopping with us! Come back soon!\n";
    return 0;
}

// ==========================
// FUNCTION IMPLEMENTATIONS
// ==========================




int getIntInput(const string& prompt, int min, int max) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if(cin.fail() || value < min || value > max) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "❌ Invalid input. Try again.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

double getDoubleInput(const string& prompt, double min) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        if(cin.fail() || value < min) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "❌ Invalid input. Try again.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}



string getStringInput(const string& prompt, bool allowEmpty) {
    string input;
    while (true) {
        cout << prompt;
        getline(cin, input);
        if (!allowEmpty && input.empty()) {
            cout << "❌ Input cannot be empty.\n";
            continue;
        }
        return input;
    }
}

void seedProducts(ProductCatalog& catalog) {
    catalog.addProduct(1, 15, "Laptop", "Electronics", 15000);
    catalog.addProduct(2, 25, "Phone", "Electronics", 9000);
    catalog.addProduct(3, 20, "Tablet", "Electronics", 7000);
    catalog.addProduct(4, 30, "Headphones", "Electronics", 1200);
    catalog.addProduct(5, 40, "Mouse", "Accessories", 450);

    catalog.addProduct(6, 35, "Keyboard", "Accessories", 700);
    catalog.addProduct(7, 18, "Monitor", "Electronics", 6000);
    catalog.addProduct(8, 22, "Printer", "Electronics", 3500);
    catalog.addProduct(9, 50, "USB", "Accessories", 150);
    catalog.addProduct(10, 28, "PowerBank", "Electronics", 950);

    catalog.addProduct(11, 14, "Desk", "Furniture", 4200);
    catalog.addProduct(12, 16, "Chair", "Furniture", 2800);
    catalog.addProduct(13, 12, "Lamp", "Furniture", 600);
    catalog.addProduct(14, 10, "Router", "Networking", 1300);
    catalog.addProduct(15, 20, "SSD", "Storage", 2200);

    catalog.addProduct(16, 18, "HDD", "Storage", 1800);
    catalog.addProduct(17, 24, "Webcam", "Electronics", 1100);
    catalog.addProduct(18, 26, "Microphone", "Electronics", 1600);
    catalog.addProduct(19, 32, "Speakers", "Electronics", 1400);
    catalog.addProduct(20, 15, "SmartWatch", "Wearables", 5000);
    catalog.addProduct(21, 12, "Football", "Sports", 400);
    catalog.addProduct(22, 10, "Tennis Racket", "Sports", 1200);
    catalog.addProduct(23, 18, "Dumbbells", "Fitness", 900);
    catalog.addProduct(24, 15, "Yoga Mat", "Fitness", 350);

    catalog.addProduct(25, 20, "Coffee Maker", "Home Appliances", 2800);
    catalog.addProduct(26, 14, "Blender", "Home Appliances", 1900);
    catalog.addProduct(27, 16, "Microwave", "Home Appliances", 6500);

    catalog.addProduct(28, 25, "Novel Book", "Books", 250);
    catalog.addProduct(29, 30, "Notebook", "Stationery", 60);
    catalog.addProduct(30, 40, "Pen Set", "Stationery", 120);

    catalog.addProduct(31, 22, "Backpack", "Bags", 750);
    catalog.addProduct(32, 18, "Wallet", "Fashion Accessories", 500);
    catalog.addProduct(33, 20, "Sunglasses", "Fashion Accessories", 900);

    catalog.addProduct(34, 15, "Perfume", "Beauty", 1600);
    catalog.addProduct(35, 25, "Hair Dryer", "Beauty Tools", 1100);

    catalog.addProduct(36, 12, "Toy Car", "Toys", 300);
    catalog.addProduct(37, 10, "Puzzle Game", "Toys", 450);

    catalog.addProduct(38, 14, "Pet Food", "Pet Supplies", 650);
    catalog.addProduct(39, 8,  "Water Bottle", "Outdoor", 220);
    catalog.addProduct(40, 6,  "Camping Tent", "Outdoor Gear", 4800);
}

// ==========================
// BROWSE PRODUCTS
// ==========================
// ==========================
// BROWSE PRODUCTS
// ==========================
void browseProducts(ProductCatalog& catalog, ReturnStack& cart) {
    while (true) {
        cout << "\n🛍️  ===== PRODUCTS (Sorted by Price from low to high) ===== 🛍️\n";
        cout << "---------------------------------------------------------------\n";
        sortAndDisplayByPrice(catalog.getRoot());
        cout << "---------------------------------------------------------------\n";

        cout << "\n1️⃣  Add product to cart by ID\n";
        cout << "2️⃣  Search product by Name\n";
        cout << "3️⃣  Back\n";

        int browseChoice = getIntInput("Choose: ", 1, 3);

        if (browseChoice == 1) {
            int id = getIntInput("Enter product ID (0 to cancel): ");
            if (id == 0) continue;

            products* product = catalog.searchProduct(id);
            if (!product) {
                cout << "❌ Product not found.\n";
                continue;
            }

            int qty = getIntInput("Enter quantity: ", 1, product->stock);
            for (int i = 0; i < qty; i++) cart.pushReturn(product->name, product->price, 1);
            cout << "✅ Added to cart successfully!\n";

            // Show options after successful addition
            cout << "\nWhat would you like to do next?\n";
            cout << "1️⃣  Continue browsing products\n";
            cout << "2️⃣  Return to main menu\n";

            int afterAddChoice = getIntInput("Choose: ", 1, 2);
            if (afterAddChoice == 2) {
                return; // Return to main menu
            }
            // If choice is 1, the loop continues and shows products again
        }
        else if (browseChoice == 2) {
            string name = getStringInput("Enter product name (0 to cancel): ");
            if (name == "0") continue;

            products* product = searchProductByName(catalog.getRoot(), name);
            if (!product) {
                cout << "❌ Product not found.\n";
                continue;
            }

            cout << "\n--- Product Details ---\n";
            cout << "ID: " << product->id
                << "\nName: " << product->name
                << "\nCategory: " << product->category
                << "\nPrice: " << product->price
                << "\nStock: " << product->stock << endl;

            int searchChoice = getIntInput("\n1. Add to cart\n2. Back\nChoose: ", 1, 2);
            if (searchChoice == 1) {
                int qty = getIntInput("Enter quantity: ", 1, product->stock);
                for (int i = 0; i < qty; i++) cart.pushReturn(product->name, product->price, 1);
                cout << "✅ Added to cart successfully!\n";

                // Show options after successful addition
                cout << "\nWhat would you like to do next?\n";
                cout << "1️⃣  Continue browsing products\n";
                cout << "2️⃣  Return to main menu\n";

                int afterAddChoice = getIntInput("Choose: ", 1, 2);
                if (afterAddChoice == 2) {
                    return; // Return to main menu
                }
                // If choice is 1, the loop continues and shows products again
            }
        }
        else break; // User chose "3. Back" from main browsing menu
    }
}

// ==========================
// VIEW CART & CHECKOUT
// ==========================
void viewCartCheckout(
    ReturnStack& cart,
    CustomerList& customers,
    OrderHistory& orderHistory,
    DeliveryQueue& deliveryQueue,
    int& orderCounter
) {
    if (cart.top == -1) {
        cout << "\n🛒 Cart is empty.\n";
        return;
    }

    cout << "\n🛒 ===== YOUR CART ===== 🛒\n";
    cart.displayCart();

    cout << "\n1️⃣  Remove last item\n2️⃣  Checkout\n3️⃣  Back\n";

    int cartChoice = getIntInput("Choose: ", 1, 3);

    if (cartChoice == 1) {
        cart.processReturn();
        return;
    }

    if (cartChoice == 3) {
        return;
    }

    // ======================
    // CHECKOUT
    // ======================
    if (cart.top == -1) {
        cout << "Cart empty. Checkout cancelled.\n";
        return;
    }

    int id = getIntInput("Customer ID: ");

    customer* existingCustomer = linearSearchCustomer(customers.getHead(), id);

    string name, email, phone, address;

    if (existingCustomer == nullptr) {
        cout << "\n🆕 New customer detected\n";
        name = getStringInput("Name: ");
        email = getStringInput("Email: ");
        phone = getStringInput("Phone: ");
        address = getStringInput("Address: ");

        customers.addCustomer(id, name, email, phone, address);
    } else {
        cout << "\n👋 Welcome back, " << existingCustomer->name << "!\n";
    }

    double total = cart.calculateTotal();

    Order order(orderCounter++, id, 0, total, "Today");
    orderHistory.addOrder(order);
    deliveryQueue.enqueueDelivery(order);

    cart.clearCart();

    cout << "\n✅ Order placed successfully!\n";
    cout << "💰 Total: " << total << " EGP\n";
}


// ==========================
// VIEW PROFILE
// ==========================
void viewProfile(CustomerList& customers, OrderHistory& orderHistory) {
    int id = getIntInput("Customer ID: ");
    customer* c = linearSearchCustomer(customers.getHead(), id);
    if(!c) { cout << "❌ Customer not found.\n"; return; }

    cout << "\n--- Profile ---\n";
    cout << "Name: " << c->name
         << "\nEmail: " << c->email
         << "\nPhone: " << c->phone
         << "\nAddress: " << c->address << endl;

    cout << "\n--- Order History ---\n";
    orderHistory.viewOrders(id);
}

// ==========================
// ADMIN PANEL
// ==========================
void adminPanel(ProductCatalog& catalog, DeliveryQueue& deliveryQueue) {
    int password = getIntInput("\nEnter admin password: ");
    if(password != 1234) { cout << "❌ Access denied!\n"; return; }

    while(true) {
        cout << "\n===== ADMIN PANEL =====\n";
        cout << "1️⃣  Add Product\n";
        cout << "2️⃣  Process Next Delivery\n";
        cout << "3️⃣  Back to Main Menu\n";

        int adminChoice = getIntInput("Choose: ", 1, 3);

        if(adminChoice == 1) {
            int id = getIntInput("Product ID: ");
            string name = getStringInput("Name: ");
            string category = getStringInput("Category: ");
            double price = getDoubleInput("Price: ", 0);
            int stock = getIntInput("Stock: ", 0);

            catalog.addProduct(id, stock, name, category, price);
            cout << "✅ Product added successfully\n";
        }
        else if(adminChoice == 2) deliveryQueue.dequeueDelivery();
        else break;
    }
}

// ==========================
// RUN SHOP SYSTEM
// ==========================
void runShopSystem() {
    ProductCatalog catalog;
    CustomerList customers;
    OrderHistory orderHistory;
    DeliveryQueue deliveryQueue;
    ReturnStack cart(10);
    int orderCounter = 1;

    seedProducts(catalog);

    while(true) {
        cout << "1️⃣  Browse Products\n";
        cout << "2️⃣  View Cart & Checkout\n";
        cout << "3️⃣  View Profile\n";
        cout << "4️⃣  Admin Panel\n";
        cout << "5️⃣  Exit\n";
        cout << "======================================\n";

        int choice = getIntInput("Choose: ", 1, 5);
        cout << "\n"<<endl;
        switch(choice) {
            case 1: browseProducts(catalog, cart); break;
            case 2: viewCartCheckout(cart, customers, orderHistory, deliveryQueue, orderCounter); break;
            case 3: viewProfile(customers, orderHistory); break;
            case 4: adminPanel(catalog, deliveryQueue); break;
            case 5: cout << "Goodbye!\n"; return;
        }
    }
}
