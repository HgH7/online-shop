//
// Created by Hassan Elsayed on 06/12/2025.
//
#include "../DS/deliveryqueue.h"
#include "../models/orders.h"
#include <iostream>
#include <string>
#include <queue>
using namespace std;

DeliveryQueue::enqueueDelivery(Order& order){
    deliveries.push(order);



}





DeliveryQueue::dequeueDelivery(){
    if (deliveries.empty()){
        return Order();
    }
    Order next = deliveries.front();
    deliveries.pop();
    return next;



}