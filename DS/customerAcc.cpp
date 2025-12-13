#include "customerAcc.h"
#include <iostream>
//ds/customerAcc.cpp
// -------- customer constructor --------
customer::customer(int Id, string Name, string Email, string Phone, string Address) {
    id = Id;
    name = Name;
    email = Email;
    phone = Phone;
    address = Address;
    next = nullptr;
}

// -------- list constructor --------
CustomerList::CustomerList() {
    head = nullptr;
}

// -------- ADD CUSTOMER (insert at end) --------
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

// -------- REMOVE CUSTOMER --------
void CustomerList::removeCustomer(int id) {
    if (head == nullptr)
        return;

    // if the head is to be removed
    if (head->id == id) {
        customer* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    customer* current = head->next;
    customer* previous = head;

    while (current != nullptr) {
        if (current->id == id) {
            previous->next = current->next;
            delete current;
            return;
        }

        previous = current;
        current = current->next;
    }
}

// -------- DISPLAY CUSTOMERS --------
void CustomerList::displayCustomers() {
    customer* temp = head;

    while (temp != nullptr) {
        cout << "ID: " << temp->id << endl;
        cout << "Name: " << temp->name << endl;
        cout << "Email: " << temp->email << endl;
        cout << "Phone: " << temp->phone << endl;
        cout << "Address: " << temp->address << endl;
        cout << "-------------------------" << endl;

        temp = temp->next;
    }
}
