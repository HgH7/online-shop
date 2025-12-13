#ifndef MODELS_PRODUCTS_H
#define MODELS_PRODUCTS_H

#include <string>
using namespace std;

class products {
public:
    int id;
    int stock;
    string name;
    string category;
    double price;

    products* left;
    products* right;

    products(int Id, int Stock, string Name, string Category, double Price);
};

#endif
