//
// Created by Hassan Elsayed on 26/11/2025.
//

#ifndef ONLINE_SHOP_SORT_H
#define ONLINE_SHOP_SORT_H
#ifndef SORT_H
#define SORT_H
using namespace std;
//Sort.h
#include "../models/products.h"
#include <iostream>

void inorderSortByPrice(products* root)
{
    if (root == nullptr)
        return;

    inorderSortByPrice(root->left);
    cout << "ID: " << root->id
      << " | " << root->name
      << " | Price: " << root->price
      << " | Stock: " << root->stock
      << endl;

    inorderSortByPrice(root->right);
}

#endif

#endif //ONLINE_SHOP_SORT_H