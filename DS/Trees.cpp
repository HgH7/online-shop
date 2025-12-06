#include "../DS/Trees.h"
#include <iostream>
#include <string>
using namespace std;

BinarySearchTree::BinarySearchTree()
{
    root = nullptr;
}

void BinarySearchTree::addProduct(int id, int stock, string name, string category, double price)
{
    products* newProduct = new products(id, stock, name, category, price);

    if (!root)
    {
        root = newProduct;
        return;
    }

    products* current = root;
    products* parent = nullptr;

    while (current != nullptr)
    {
        parent = current;
        if (id < current->id)
            current = current->left;
        else
            current = current->right;
    }

    if (id < parent->id)
        parent->left = newProduct;
    else
        parent->right = newProduct;
}

void BinarySearchTree::searchProduct(int id)
{
    products* current = root;

    while (current != nullptr)
    {
        if (id == current->id)
        {
            cout << "item category = " << current->category << endl
                 << "item name = " << current->name << endl
                 << "item price = " << current->price << endl;
            return;
        }
        else if (id < current->id)
            current = current->left;
        else
            current = current->right;
    }

    cout << "sorry the product you are looking for is not available" << endl;
}

void BinarySearchTree::removeProduct(int id)
{
    products* parent = nullptr;
    products* current = root;

    // Find node
    while (current != nullptr && current->id != id)
    {
        parent = current;
        if (id < current->id)
            current = current->left;
        else
            current = current->right;
    }

    if (current == nullptr)
    {
        cout << "product not found" << endl;
        return;
    }

    // Case: two children → find successor
    if (current->left != nullptr && current->right != nullptr)
    {
        products* successorParent = current;
        products* successor = current->right;

        while (successor->left != nullptr)
        {
            successorParent = successor;
            successor = successor->left;
        }

        // Copy successor data
        current->id = successor->id;
        current->name = successor->name;
        current->category = successor->category;
        current->price = successor->price;
        current->stock = successor->stock;

        // Now delete successor instead
        current = successor;
        parent = successorParent;
    }

    // Case: 0 or 1 child
    products* child = (current->left != nullptr) ? current->left : current->right;

    if (parent == nullptr)
    {
        root = child;
    }
    else if (parent->left == current)
    {
        parent->left = child;
    }
    else
    {
        parent->right = child;
    }

    delete current;
}
