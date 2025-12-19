//
// Created by Hassan Elsayed on 26/11/2025.
//
//Search.h
#ifndef ONLINE_SHOP_SEARCH_H
#define ONLINE_SHOP_SEARCH_H
#ifndef SEARCH_H
#define SEARCH_H

#include "../models/customers.h"

customer* linearSearchCustomer(customer* head, int id)
{
    while (head != nullptr)
    {
        if (head->id == id)
            return head;
        head = head->next;
    }
    return nullptr;
}
// Search product by name (linear search on BST)
products* searchProductByName(products* root, const string& name) {
    if (!root) return nullptr;

    // Check current node
    if (root->name == name)
        return root;

    // Search left subtree
    products* leftResult = searchProductByName(root->left, name);
    if (leftResult) return leftResult;

    // Search right subtree
    return searchProductByName(root->right, name);
}

#endif

#endif //ONLINE_SHOP_SEARCH_H