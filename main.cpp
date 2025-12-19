#include "./DS/products.h"
#include "./DS/customerAcc.h"
#include "./DS/cartSystem.h"
#include "./DS/orderHistory.h"
#include "./DS/deliveryqueue.h"

#include "./Algo/Search.h"
#include "./Algo/Sort.h"

using namespace std;

void seedProducts(ProductCatalog& catalog) {
    catalog.addProduct(1, 10, "Laptop", "Electronics", 15000);
    catalog.addProduct(2, 20, "Phone", "Electronics", 8000);
    catalog.addProduct(3, 15, "Keyboard", "Accessories", 700);
    catalog.addProduct(4, 30, "Mouse", "Accessories", 450);
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
        cout << "3. Remove Last Item from Cart\n";
        cout << "4. Exit\n";
        cout << "Choose: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer

        if (choice == 1) {
            cout << "\n=== Products sorted by price ===\n";
            inorderSortByPrice(catalog.getRoot());

            // Now let user select a product
            cout << "\nEnter product name to add to cart (or '0' to go back): ";
            string productName;
            getline(cin, productName);

            if (productName != "0") {
                products* product = nullptr;

                if (productName == "Laptop" || productName == "laptop") {
                    product = new products(1, 10, "Laptop", "Electronics", 15000);
                }
                else if (productName == "Phone" || productName == "phone") {
                    product = new products(2, 20, "Phone", "Electronics", 8000);
                }
                else if (productName == "Keyboard" || productName == "keyboard") {
                    product = new products(3, 15, "Keyboard", "Accessories", 700);
                }
                else if (productName == "Mouse" || productName == "mouse") {
                    product = new products(4, 30, "Mouse", "Accessories", 450);
                }

                if (product != nullptr) {
                    cout << "Enter quantity: ";
                    int quantity;
                    cin >> quantity;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    if (quantity > 0 && quantity <= product->stock) {
                        // Add to cart
                        cart.pushReturn(product->name,product->price,quantity);
                        cout << "Added " << quantity << " x " << product->name
                            << " (Price: " << product->price << " each)"
                            << " to cart!\n";
                    }
                    else {
                        cout << "Invalid quantity or insufficient stock!\n";
                    }

                    delete product; // Clean up memory
                }
                else {
                    cout << "Product not found!\n";
                }
            }
        }

        else if (choice == 2) {
            cart.displayCart();

            // Ask if user wants to checkout
            cout << "\nDo you want to checkout? (y/n): ";
            char checkoutChoice;
            cin >> checkoutChoice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (checkoutChoice == 'y' || checkoutChoice == 'Y') {
                int id;
                string name, email, phone, address;

                cout << "\n=== Checkout ===\n";
                cout << "Customer ID: ";
                cin >> id;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Name: ";
                getline(cin, name);

                cout << "Email: ";
                getline(cin, email);

                cout << "Phone: ";
                getline(cin, phone);

                cout << "Address: ";
                getline(cin, address);

                customers.addCustomer(id, name, email, phone, address);

                // Calculate total based on cart items
                // You'll need to implement a method to get cart total
                // For now, let's manually calculate based on what we know

                cout << "\nCalculating total...\n";
                cout << "Enter the total from your cart display above: ";
                double total;
                cin >> total;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                Order order(orderCounter++, id, 0, total, "Today");
                orderHistory.addOrder(order);
                deliveryQueue.enqueueDelivery(order);

                cout << "\n✓ Order placed successfully!\n";
                cout << "Total Amount: " << total << " EGP\n";
            }
            else {
                cout << "Returning to main menu...\n";
            }
        }

        else if (choice == 3) {
            cart.processReturn();
        }

        else if (choice == 4) {
            int id;
            string name, email, phone, address;

            cout << "\nCustomer ID: ";
            cin >> id;
            cout << "Name: ";
            cin >> name;
            cout << "Email: ";
            cin >> email;
            cout << "Phone: ";
            cin >> phone;
            cout << "Address: ";
            cin >> address;

            customers.addCustomer(id, name, email, phone, address);

            double total;
            cout << "Enter total amount: ";
            cin >> total;

            Order order(orderCounter++, id, 0, total, "Today");
            orderHistory.addOrder(order);
            deliveryQueue.enqueueDelivery(order);

            cout << "Order placed successfully\n";
        }

        else if (choice == 5) {
            cout << "Goodbye!\n";
            break;
        }

        else {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}
