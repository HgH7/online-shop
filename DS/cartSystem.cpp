#include "cartSystem.h"
#include <iostream>
//ds/cartSystem.cpp
using namespace std;

ReturnStack::ReturnStack(int size) {
    maxSize = size;
    top = -1;
    items = new CartItem[size];
}

void ReturnStack::pushReturn(string itemName, double price, int quantity) {
    if (top >= maxSize - 1) {
        cout << "Cart is full!\n";
        return;
    }
    top++;
    items[top].name = itemName;
    items[top].price = price;
    items[top].quantity = quantity;
}

void ReturnStack::processReturn() {
    if (top < 0) {
        cout << "Cart is empty!\n";
        return;
    }
    cout << "Removed: " << items[top].name << "\n";
    top--;
}

void ReturnStack::displayCart() {
    if (top < 0) {
        cout << "Cart is empty!\n";
        return;
    }
    cout << "\n=== Your Cart ===\n";
    for (int i = 0; i <= top; i++) {
        double itemTotal = items[i].price * items[i].quantity;
        cout << (i + 1) << ". " << items[i].name
            << " x " << items[i].quantity
            << " @ " << items[i].price
            << " = " << itemTotal << " EGP\n";
    }
    cout << "\n--- Total: " << calculateTotal() << " EGP ---\n";
}

double ReturnStack::calculateTotal() {
    double total = 0;
    for (int i = 0; i <= top; i++) {
        total += items[i].price * items[i].quantity;
    }
    return total;
}

void ReturnStack::clearCart() {
    top = -1;
}