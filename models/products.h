#ifndef ONLINE_SHOP_PRODUCTS_H
#define ONLINE_SHOP_PRODUCTS_H
#include <string>
class products
{
public:
    int id;
    int stock;
    string name;
    string category;
    double price;
    products* right;
    products* left;


products(int Id,int Stock,string Name,string Category,double Price):id(Id),stock(Stock),name(Name),category(Category),price(Price),left(nullptr),right(nullptr)
{}


};





#endif //ONLINE_SHOP_PRODUCTS_H