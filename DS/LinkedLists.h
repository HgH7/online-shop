#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H

#include "../models/customers.h"
#include <iostream>
using namespace std;

class CustomerList {
private:
    class Node {
    public:
        Customer data;
        Node* next;
        Node(const Customer& c) : data(c), next(nullptr) {}
    };

    Node* head;

public:
    CustomerList();
    void addCustomer(const Customer &c);
    void removeCustomer(int id);
    void displayCustomers() const;
};

#endif
