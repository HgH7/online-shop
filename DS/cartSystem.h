#ifndef ONLINE_SHOP_CARTSYSTEM_H
#define ONLINE_SHOP_CARTSYSTEM_H
#include <string>
using namespace std;

struct CartItem {
    string name;
    double price;
    int quantity;
};

class ReturnStack {
public:
    int top;
    int maxSize;
    CartItem* items;  // Changed from string* to CartItem*

    ReturnStack(int size);
    void pushReturn(string itemName, double price, int quantity);  // Updated signature
    void processReturn();
    void displayCart();
    double calculateTotal();  // New method to calculate total
};
#endif
