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

    Order(int oID, int cID, int pID, double t, string d) {
        orderID = oID;
        customerID = cID;
        productID = pID;
        total = t;
        date = d;
    }
};

#endif
