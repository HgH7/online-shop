#ifndef DS_CUSTOMERACC_H
#define DS_CUSTOMERACC_H
//Ds/customerAcc.h
#include "../models/customers.h"

class CustomerList {
private:
    customer* head;

public:
    CustomerList();

    void addCustomer(int id, string name, string email, string phone, string address);
    void removeCustomer(int id);
    void displayCustomers();
};

#endif
