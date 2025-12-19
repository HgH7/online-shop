#include <iostream>
#include <limits>

#include "./DS/products.h"
#include "./DS/customerAcc.h"
#include "./DS/cartSystem.h"
#include "./DS/orderHistory.h"
#include "./DS/deliveryqueue.h"

#include "./Algo/Search.h"
#include "./Algo/Sort.h"

using namespace std;

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

int main() {
    ProductCatalog catalog;
    CustomerList customers;
    OrderHistory orderHistory;
    DeliveryQueue deliveryQueue;
    ReturnStack cart(10);

    seedProducts(catalog);

    int choice;
    int orderCounter = 1;

    cout << "=== ONLINE SHOP SYSTEM ===\n";

    while (true) {
        cout << "\n1. Browse Products\n";
        cout << "2. View Cart & Checkout\n";
        cout << "3. View Profile\n";
        cout << "4. Admin panel\n";
        cout << "5. Exit\n";
        cout << "Choose: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // ===========================
        // 1. BROWSE PRODUCTS
        // ===========================
       // ===========================
// 1. BROWSE PRODUCTS
// ===========================
        if (choice == 1) {
            while (true) {
                cout << "\n=== Products (Sorted by Price from low to high) ===\n";
                sortAndDisplayByPrice(catalog.getRoot());

                cout << "\n1. Add product to cart by ID\n";
                cout << "2. Search for product by ID\n";
                cout << "3. Back\n";
                cout << "Choose: ";

                int browseChoice;
                cin >> browseChoice;

                // ---- ADD TO CART ----
                if (browseChoice == 1) {
                    int id;
                    cout << "Enter product ID (0 to cancel): ";
                    cin >> id;

                    if (id == 0) continue;

                    products* product = catalog.searchProduct(id);
                    if (!product) {
                        cout << "❌ Product not found.\n";
                        continue;
                    }

                    int qty;
                    cout << "Enter quantity: ";
                    cin >> qty;

                    if (qty <= 0 || qty > product->stock) {
                        cout << "❌ Invalid quantity.\n";
                        continue;
                    }

                    for (int i = 0; i < qty; i++) {
                        cart.pushReturn(product->name, product->price, 1);
                    }

                    cout << "✓ Added to cart\n";
                }

                // ---- SEARCH PRODUCT ----
                // ---- SEARCH PRODUCT BY NAME ----
                else if (browseChoice == 2) {
                    cin.ignore();  // clear newline
                    string name;
                    cout << "Enter product name to search (or '0' to cancel): ";
                    getline(cin, name);

                    if (name == "0") continue;

                    products* product = searchProductByName(catalog.getRoot(), name);
                    if (!product) {
                        cout << "❌ Product not found.\n";
                        continue;
                    }

                    // Show ONLY the searched product
                    cout << "\n=== Product Found ===\n";
                    cout << "ID: " << product->id
                        << "\nName: " << product->name
                        << "\nCategory: " << product->category
                        << "\nPrice: " << product->price
                        << "\nStock: " << product->stock << endl;

                    // Sub-menu
                    while (true) {
                        cout << "\n1. Add to cart\n";
                        cout << "2. Back\n";
                        cout << "Choose: ";

                        int searchChoice;
                        cin >> searchChoice;

                        if (searchChoice == 1) {
                            int qty;
                            cout << "Enter quantity: ";
                            cin >> qty;

                            if (qty <= 0 || qty > product->stock) {
                                cout << "❌ Invalid quantity.\n";
                                continue;
                            }

                            for (int i = 0; i < qty; i++) {
                                cart.pushReturn(product->name, product->price, 1);
                            }

                            cout << "✓ Added to cart\n";
                            break;  // go back to browse menu
                        }
                        else if (searchChoice == 2) {
                            break;  // back to browse menu
                        }
                        else {
                            cout << "Invalid choice\n";
                        }
                    }
                }



                // ---- BACK ----
                else if (browseChoice == 3) {
                    break;
                }

                else {
                    cout << "Invalid choice\n";
                }
            }
        }


        // ===========================
        // 2. CART & CHECKOUT
        // ===========================
        else if (choice == 2) {
            if (cart.top == -1) {
                cout << "Cart is empty.\n";
                continue;
            }

            cart.displayCart();

            cout << "\n1. Remove last item\n";
            cout << "2. Checkout\n";
            cout << "3. Back\n";
            cout << "Choose: ";

            int cartChoice;
            cin >> cartChoice;

            if (cartChoice == 1) {
                cart.processReturn();
            }

            else if (cartChoice == 2) {
                if (cart.top == -1) {
                    cout << "Cart empty. Checkout cancelled.\n";
                    continue;
                }

                int id;
                string name, email, phone, address;

                cout << "Customer ID: ";
                cin >> id;
                cin.ignore();

                cout << "Name: ";
                getline(cin, name);
                cout << "Email: ";
                getline(cin, email);
                cout << "Phone: ";
                getline(cin, phone);
                cout << "Address: ";
                getline(cin, address);

                customers.addCustomer(id, name, email, phone, address);

                double total = cart.calculateTotal();

                Order order(orderCounter++, id, 0, total, "Today");
                orderHistory.addOrder(order);
                deliveryQueue.enqueueDelivery(order);

                cout << "✓ Order placed. Total = " << total << " EGP\n";
            }
        }

        // ===========================
        // 3. PROFILE
        // ===========================
        else if (choice == 3) {
            int id;
            cout << "Customer ID: ";
            cin >> id;

            customer* c = linearSearchCustomer(customers.getHead(), id);
            if (!c) {
                cout << "Customer not found.\n";
                continue;
            }

            cout << "\nName: " << c->name
                 << "\nEmail: " << c->email
                 << "\nPhone: " << c->phone
                 << "\nAddress: " << c->address << endl;

            cout << "\nOrder History:\n";
            orderHistory.viewOrders(id);
        }



        // ===========================
        // 4. ADMIN PAGE
        // ===========================
        else if (choice == 4) {
            int password;
            cout << "\nEnter admin password: ";
            cin >> password;

            if (password != 1234) {
                cout << "❌ Access denied!\n";
                continue;
            }

            int adminChoice;
            while (true) {
                cout << "\n=== ADMIN PAGE ===\n";
                cout << "1. Add Product\n";
                cout << "2. Process Next Delivery\n";
                cout << "3. Back to Main Menu\n";
                cout << "Choose: ";
                cin >> adminChoice;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                // ---- ADD PRODUCT ----
                if (adminChoice == 1) {
                    int id, stock;
                    string name, category;
                    double price;

                    cout << "Product ID: ";
                    cin >> id;
                    cin.ignore();

                    cout << "Name: ";
                    getline(cin, name);

                    cout << "Category: ";
                    getline(cin, category);

                    cout << "Price: ";
                    cin >> price;

                    cout << "Stock: ";
                    cin >> stock;

                    catalog.addProduct(id, stock, name, category, price);
                    cout << "✓ Product added successfully\n";
                }

                // ---- PROCESS DELIVERY ----
                else if (adminChoice == 2) {
                    deliveryQueue.dequeueDelivery();
                }

                // ---- BACK ----
                else if (adminChoice == 3) {
                    break;
                }

                else {
                    cout << "Invalid choice\n";
                }
            }
        }
        // ===========================
        // EXIT
        // ===========================
        else if (choice == 5) {
            cout << "Goodbye!\n";
            break;
        }
    }

    return 0;
}
