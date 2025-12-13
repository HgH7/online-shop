#ifndef ONLINE_SHOP_DELIVERYQUEUE_H
#define ONLINE_SHOP_DELIVERYQUEUE_H
//DS/deliveryqueue.h
#include "../models/orders.h"
using namespace std;

class DeliveryNode {
public:
    Order order;
    DeliveryNode* next;

    DeliveryNode(Order order);
};

class DeliveryQueue {
private:
    DeliveryNode* front;
    DeliveryNode* rear;

public:
    DeliveryQueue();

    void enqueueDelivery(Order order);
    Order dequeueDelivery();
    bool isEmpty();
};

#endif
