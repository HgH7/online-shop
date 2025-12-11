#ifndef ORDER_H
#define ORDER_H

#include <string>
using namespace std;

class Order {
public:
    int orderID;
    int customerID;
    int productID;
    double total;
    string date;

    Order() {}

    Order(int orderID, int customerID, int productID, double total, string date)
        : orderID(orderID), customerID(customerID), productID(productID), total(total), date(date) {}
};

#endif
