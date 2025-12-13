#ifndef ONLINE_SHOP_CARTSYSTEM_H
#define ONLINE_SHOP_CARTSYSTEM_H

#include <string>
using namespace std;

class ReturnStack {
public:
    int top;
    int maxSize;
    string* items;

    ReturnStack(int size);

    void pushReturn(string item);
    void processReturn();
};

#endif
