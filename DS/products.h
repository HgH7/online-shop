#ifndef DS_PRODUCTS_H
#define DS_PRODUCTS_H

#include "../models/products.h"
#include <string>

class ProductCatalog {
private:
    products* root;

    void displayByCategory(products* node, string category);
    void displayCategories(products* node);

public:
    ProductCatalog();

    void addProduct(int id, int stock, string name, string category, double price);
    void removeProduct(int id);
    products* searchProduct(int id);

    products* getRoot();
    void showProductsByCategory(string category);
    void showAllCategories();
};

#endif
