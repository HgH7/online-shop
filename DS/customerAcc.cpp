#include "customerAcc.h"
#include <iostream>
using namespace std;

customer::customer(int Id, string Name, string Email, string Phone, string Address) {
    id = Id;
    name = Name;
    email = Email;
    phone = Phone;
    address = Address;
    next = nullptr;
}

CustomerList::CustomerList() {
    head = nullptr;
}

void CustomerList::addCustomer(int id, string name, string email, string phone, string address) {
    customer* newNode = new customer(id, name, email, phone, address);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    customer* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
}

void CustomerList::removeCustomer(int id) {
    if (head == nullptr)
        return;

    if (head->id == id) {
        customer* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    customer* curr = head->next;
    customer* prev = head;

    while (curr != nullptr) {
        if (curr->id == id) {
            prev->next = curr->next;
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

void CustomerList::displayCustomers() {
    customer* temp = head;
    while (temp != nullptr) {
        cout << temp->id << " - " << temp->name << endl;
        temp = temp->next;
    }
}

customer* CustomerList::getHead() {
    return head;
}
