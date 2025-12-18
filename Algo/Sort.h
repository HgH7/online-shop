//
// Created by Hassan Elsayed on 26/11/2025.
//

#ifndef ONLINE_SHOP_SORT_H
#define ONLINE_SHOP_SORT_H
#ifndef SORT_H
#define SORT_H
//Sort.h
#include "../models/products.h"
#include <iostream>

void inorderSortByPrice(products* root)
{
    if (root == nullptr)
        return;

    inorderSortByPrice(root->left);
    std::cout << root->name << " - " << root->price << std::endl;
    inorderSortByPrice(root->right);
}

#endif

#endif //ONLINE_SHOP_SORT_H