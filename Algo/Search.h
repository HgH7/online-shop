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

#endif

#endif //ONLINE_SHOP_SEARCH_H