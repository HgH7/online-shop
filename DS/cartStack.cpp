#include "../DS/QueueStacks.h"
#include <iostream>
using namespace std;



void ReturnStack::pushReturn(string item){
    if (top == maxSize -1){
        cout<<"Stack is full Cannot add:"<< item <<endl;
        return;
    }
    items[++top]=item;
    cout<<"Return item added: "<< item<<endl;
}

void ReturnStack::processReturn(){
    if(top == -1){
        cout<<"No return items to process"<<endl;
        return;
    }


    string item = items[top--];
    cout<<"processing return item:"<<item<<endl;
}