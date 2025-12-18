#include "orderHistory.h"
#include <iostream>
using namespace std;

OrderNode::OrderNode(Order o) {
    order = o;
    prev = nullptr;
    next = nullptr;
}

OrderHistory::OrderHistory() {
    head = nullptr;
    tail = nullptr;
}

void OrderHistory::addOrder(Order order) {
    OrderNode* newNode = new OrderNode(order);

    if (head == nullptr) {
        head = tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void OrderHistory::viewOrders(int customerID) {
    OrderNode* temp = head;

    while (temp != nullptr) {
        if (temp->order.customerID == customerID) {
            cout << "Order ID: " << temp->order.orderID << endl;
            cout << "Product ID: " << temp->order.productID << endl;
            cout << "Total: " << temp->order.total << endl;
            cout << "Date: " << temp->order.date << endl;
            cout << "---------------------" << endl;
        }
        temp = temp->next;
    }
}
