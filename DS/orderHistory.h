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
