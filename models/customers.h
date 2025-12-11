#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

class Customer {
public:
    int id;
    string name;
    string email;
    string phone;
    string address;

    Customer(int id, string name, string email, string phone, string address)
        : id(id), name(name), email(email), phone(phone), address(address) {}

    Customer() {}
};

#endif
