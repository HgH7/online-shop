//
// Created by Hassan Elsayed on 06/12/2025.
//
#ifndef ONLINE_SHOP_DELIVERYQUEUE_H
#define ONLINE_SHOP_DELIVERYQUEUE_H
#include "../models/orders.h"
#include <string>
#include <queue>

class DeliveryQueue
{
private :
queue<Order> deliveries;



public:
    void enqueueDelivery(Order& order );
    void dequeueDelivery();
};
#endif //ONLINE_SHOP_DELIVERYQUEUE_H