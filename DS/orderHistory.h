//
// Created by Hassan Elsayed on 13/12/2025.
//

#ifndef ONLINE_SHOP_ORDERHISTORY_H
#define ONLINE_SHOP_ORDERHISTORY_H
#ifndef DS_ORDERHISTORY_H
#define DS_ORDERHISTORY_H

#include "../models/orders.h"

class OrderNode {
public:
    Order order;
    OrderNode* prev;
    OrderNode* next;

    OrderNode(Order o);
};

class OrderHistory {
private:
    OrderNode* head;
    OrderNode* tail;

public:
    OrderHistory();

    void addOrder(Order order);
    void viewOrders(int customerID);
};

#endif

#endif //ONLINE_SHOP_ORDERHISTORY_H