//
// Created by Hassan Elsayed on 11/12/2025.
//

#ifndef ONLINE_SHOP_LINKEDLIST_H
#define ONLINE_SHOP_LINKEDLIST_H
#include "../models/orders.h"




class OrderList {
private:
    class Node {
    public:
        Order data;
        Node* prev;
        Node* next;

        Node(const Order& o) : data(o), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    OrderList();

    void addOrder(const Order &o);
    void viewOrders(int customerID) const;
};

#endif //ONLINE_SHOP_LINKEDLIST_H