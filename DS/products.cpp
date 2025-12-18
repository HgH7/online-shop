#include "products.h"
#include <iostream>
using namespace std;

products::products(int Id, int Stock, string Name, string Category, double Price) {
    id = Id;
    stock = Stock;
    name = Name;
    category = Category;
    price = Price;
    left = nullptr;
    right = nullptr;
}

ProductCatalog::ProductCatalog() {
    root = nullptr;
}

void ProductCatalog::addProduct(int id, int stock, string name, string category, double price) {
    products* newNode = new products(id, stock, name, category, price);

    if (root == nullptr) {
        root = newNode;
        return;
    }

    products* current = root;
    products* parent = nullptr;

    while (current != nullptr) {
        parent = current;
        if (id < current->id)
            current = current->left;
        else
            current = current->right;
    }

    if (id < parent->id)
        parent->left = newNode;
    else
        parent->right = newNode;
}

products* ProductCatalog::searchProduct(int id) {
    products* current = root;

    while (current != nullptr) {
        if (id == current->id)
            return current;
        if (id < current->id)
            current = current->left;
        else
            current = current->right;
    }
    return nullptr;
}

products* ProductCatalog::getRoot() {
    return root;
}

void ProductCatalog::displayByCategory(products* node, string category) {
    if (node == nullptr)
        return;

    displayByCategory(node->left, category);

    if (node->category == category) {
        cout << node->id << " - " << node->name << " - " << node->price << endl;
    }

    displayByCategory(node->right, category);
}

void ProductCatalog::showProductsByCategory(string category) {
    displayByCategory(root, category);
}

void ProductCatalog::displayCategories(products* node) {
    if (node == nullptr)
        return;

    displayCategories(node->left);
    cout << node->category << endl;
    displayCategories(node->right);
}

void ProductCatalog::showAllCategories() {
    displayCategories(root);
}
