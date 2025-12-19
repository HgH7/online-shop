#ifndef ONLINE_SHOP_SORT_H
#define ONLINE_SHOP_SORT_H

#include "../models/products.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// --------------------------------------------------
// Collect all products from BST into a vector
// --------------------------------------------------
void collectProducts(products* root, vector<products*>& list)
{
    if (root == nullptr)
        return;

    collectProducts(root->left, list);
    list.push_back(root);
    collectProducts(root->right, list);
}

// --------------------------------------------------
// Sort products by price and display them
// --------------------------------------------------
void sortAndDisplayByPrice(products* root)
{
    vector<products*> list;

    collectProducts(root, list);

    sort(list.begin(), list.end(),
        [](products* a, products* b)
        {
            return a->price < b->price;
        });

    cout << "\n=== Products (Sorted by Price) ===\n";

    for (auto p : list)
    {
        cout << "ID: " << p->id
            << " | " << p->name
            << " | Price: " << p->price
            << " | Stock: " << p->stock
            << endl;
    }
}

#endif // ONLINE_SHOP_SORT_H