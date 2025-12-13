#ifndef DS_PRODUCTS_H
#define DS_PRODUCTS_H
//DS/products.h
#include "../models/products.h"

class ProductCatalog {
private:
    products* root;

public:
    ProductCatalog();

    void addProduct(int id, int stock, string name, string category, double price);
    void removeProduct(int id);
    products* searchProduct(int id);
};

#endif
