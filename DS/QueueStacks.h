#ifndef ONLINE_SHOP_QUEUESTACKS_H
#define ONLINE_SHOP_QUEUESTACKS_H

class ReturnStack{
public:
    int top;
    int maxSize;
    string* items;



    ReturnStack(int size){

        maxSize = size;
        items = new string[maxSize];

        top = -1;

    }

    void pushReturn(string item);
    void processReturn();

};


#endif //ONLINE_SHOP_QUEUESTACKS_H