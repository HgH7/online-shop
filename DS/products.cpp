#include "products.h"
//Ds/products.cpp
// -------- products constructor --------
products::products(int Id, int Stock, string Name, string Category, double Price) {
    id = Id;
    stock = Stock;
    name = Name;
    category = Category;
    price = Price;
    left = nullptr;
    right = nullptr;
}

// -------- ProductCatalog constructor --------
ProductCatalog::ProductCatalog() {
    root = nullptr;
}

// -------- ITERATIVE ADD PRODUCT --------
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
        else if (id > current->id)
            current = current->right;
        else
            return; // duplicate id, do nothing
    }

    if (id < parent->id)
        parent->left = newNode;
    else
        parent->right = newNode;
}

// -------- ITERATIVE SEARCH PRODUCT --------
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

// -------- ITERATIVE REMOVE PRODUCT --------
void ProductCatalog::removeProduct(int id) {
    products* current = root;
    products* parent = nullptr;

    // find the node
    while (current != nullptr && current->id != id) {
        parent = current;

        if (id < current->id)
            current = current->left;
        else
            current = current->right;
    }

    if (current == nullptr)
        return; // not found

    // CASE 1: no children
    if (current->left == nullptr && current->right == nullptr) {
        if (parent == nullptr)
            root = nullptr;
        else if (parent->left == current)
            parent->left = nullptr;
        else
            parent->right = nullptr;

        delete current;
        return;
    }

    // CASE 2: one child
    if (current->left == nullptr || current->right == nullptr) {
        products* child = (current->left != nullptr) ? current->left : current->right;

        if (parent == nullptr)
            root = child;
        else if (parent->left == current)
            parent->left = child;
        else
            parent->right = child;

        delete current;
        return;
    }

    // CASE 3: two children – find successor (smallest in right subtree)
    products* successor = current->right;
    products* successorParent = current;

    while (successor->left != nullptr) {
        successorParent = successor;
        successor = successor->left;
    }

    // copy successor data
    current->id = successor->id;
    current->name = successor->name;
    current->category = successor->category;
    current->price = successor->price;
    current->stock = successor->stock;

    // delete successor node
    if (successorParent->left == successor)
        successorParent->left = successor->right;
    else
        successorParent->right = successor->right;

    delete successor;
}
