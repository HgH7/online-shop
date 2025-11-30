//
// Created by Hassan Elsayed on 26/11/2025.
//
#ifndef ONLINE_SHOP_TREES_H
#define ONLINE_SHOP_TREES_H
#include "../models/products.h"
#include <string>
using namespace std;
class BinarySearchTree
{
private:
    products* root;

public:
    BinarySearchTree();
    void addProduct( int id,int stock,string name,string category,double price);
    void removeProduct(int id);
    void searchProduct(int id);
};








#endif //ONLINE_SHOP_TREES_H