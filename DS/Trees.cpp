#include "../DS/Trees.h"
#include <iostream>
#include <string>
using namespace std;

BinarySearchTree::BinarySearchTree()
{
    root = nullptr;
};
void BinarySearchTree::addProduct(int id,int stock,string name,string category,double price)
{
    products* newProduct = new products(id,stock,name,category,price);
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
        if (id<current->id)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }

    }
    if (id < parent->id)
    {
        parent->left = newProduct;
    }
    else
        parent->right = newProduct;

};
void BinarySearchTree::searchProduct(int id)
{
    products* current = root;
    while ( current!= nullptr)
    {
        if (id == current->id)
        {
            cout<<"item category = "<<current->category<<endl<<
                "item name = "<<current->name<<endl<<
                    "item price = "<<current->price<<endl;
            return;
        }
        else if (id<current->id)
        {
            current=current->left;
        }
        else
            current = current->right;
    }
    cout<<"sorry the product you are looking for is not available "<<endl;

};





