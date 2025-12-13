#include "deliveryqueue.h"
#include <iostream>
//DS/deliveryqueue.cpp
using namespace std;

// Node constructor
DeliveryNode::DeliveryNode(Order o) {
    order = o;
    next = nullptr;
}

// Queue constructor
DeliveryQueue::DeliveryQueue() {
    front = nullptr;
    rear = nullptr;
}

void DeliveryQueue::enqueueDelivery(Order order) {
    DeliveryNode* newNode = new DeliveryNode(order);

    if (rear == nullptr) {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

Order DeliveryQueue::dequeueDelivery() {
    if (front == nullptr) {
        cout << "No deliveries to process." << endl;
        return Order();
    }

    DeliveryNode* temp = front;
    Order data = front->order;

    front = front->next;
    if (front == nullptr)
        rear = nullptr;

    delete temp;
    return data;
}

bool DeliveryQueue::isEmpty() {
    return front == nullptr;
}
