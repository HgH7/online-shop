#include <iostream>
#include <string>

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
        cout << "2. View Cart\n";
        cout << "3. Remove Last Item from Cart\n";
        cout << "4. Checkout\n";
        cout << "5. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\nProducts sorted by price:\n";
            inorderSortByPrice(catalog.getRoot());
        }

        else if (choice == 2) {
            cart.displayCart();
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
