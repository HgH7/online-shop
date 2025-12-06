//
// Created by Hassan Elsayed on 26/11/2025.
//

#ifndef ONLINE_SHOP_ORDERS_H
#define ONLINE_SHOP_ORDERS_H
#include <string>
using namespace std;
class Order{
public:
    int orderID;
    string customername;
    string productsname;
    int quantity;






    Order(int Orderid,string Customername,string Productsname,int Quantity):
    orderID(Orderid),customername(Customername),productsname(Productsname),quantity(Quantity){}






};
#endif //ONLINE_SHOP_ORDERS_H