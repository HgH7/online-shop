//
// Created by Hassan Elsayed
//
#ifndef ONLINE_SHOP_SEARCH_H
#define ONLINE_SHOP_SEARCH_H

#include "../models/customers.h"
#include "../models/products.h"
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

// ----------------------------
// Linear search for customer by ID
// ----------------------------
customer* linearSearchCustomer(customer* head, int id) {
    while (head != nullptr) {
        if (head->id == id)
            return head;
        head = head->next;
    }
    return nullptr;
}

// ----------------------------
// Helper: Convert string to lowercase
// ----------------------------
inline string toLowerCase(const string& str) {
    string lower = str;
    transform(lower.begin(), lower.end(), lower.begin(),
        [](unsigned char c) { return tolower(c); });
    return lower;
}

// ----------------------------
// Search product by name (case-insensitive)
// ----------------------------
products* searchProductByName(products* root, const string& name) {
    if (!root) return nullptr;

    if (toLowerCase(root->name) == toLowerCase(name))
        return root;

    products* leftResult = searchProductByName(root->left, name);
    if (leftResult) return leftResult;

    return searchProductByName(root->right, name);
}

#endif // ONLINE_SHOP_SEARCH_H
