#ifndef MODELS_CUSTOMER_H
#define MODELS_CUSTOMER_H

#include <string>
using namespace std;

class customer {
public:
    int id;
    string name;
    string email;
    string phone;
    string address;

    customer* next;

    customer(int Id, string Name, string Email, string Phone, string Address);
};

#endif
