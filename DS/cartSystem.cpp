#include "cartSystem.h"
#include <iostream>
//ds/cartSystem.cpp
using namespace std;

ReturnStack::ReturnStack(int size) {
    maxSize = size;
    items = new string[maxSize];
    top = -1;
}

void ReturnStack::pushReturn(string item) {
    if (top == maxSize - 1) {
        cout << "Stack is full. Cannot add: " << item << endl;
        return;
    }

    items[++top] = item;
    cout << "Return item added: " << item << endl;
}

void ReturnStack::processReturn() {
    if (top == -1) {
        cout << "No return items to process." << endl;
        return;
    }

    string item = items[top--];
    cout << "Processing return item: " << item << endl;
}
