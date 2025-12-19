#ifndef ONLINE_SHOP_SORT_H
#define ONLINE_SHOP_SORT_H

#include "../models/products.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Collect all products from BST into a vector
void collectProducts(products* root, vector<products*>& list)
{
    if (!root) return;
    collectProducts(root->left, list);
    list.push_back(root);
    collectProducts(root->right, list);
}

// Sort products by price and display them (simple GUI)
void sortAndDisplayByPrice(products* root)
{
    vector<products*> list;
    collectProducts(root, list);

    sort(list.begin(), list.end(),
         [](products* a, products* b) { return a->price < b->price; });

    cout << "\nID  | Name           | Category       | Price | Stock\n";
    cout << "------------------------------------------------------\n";

    for (auto p : list)
    {
        cout << p->id << "   | "
             << p->name << "   | "
             << p->category << "   | "
             << p->price << "   | "
             << p->stock << "\n";
    }

    cout << "------------------------------------------------------\n";
}

#endif // ONLINE_SHOP_SORT_H
