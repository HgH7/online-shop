//
// Created by Hassan Elsayed on 13/12/2025.
//
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
    OrderNode* current = head;

    while (current != nullptr) {
        if (current->order.customerID == customerID) {
            cout << "Order ID: " << current->order.orderID << endl;
            cout << "Product ID: " << current->order.productID << endl;
            cout << "Total: " << current->order.total << endl;
            cout << "Date: " << current->order.date << endl;
            cout << "-------------------------" << endl;
        }
        current = current->next;
    }
}
