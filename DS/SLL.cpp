#include "../DS/linkedList.h"
#include <iostream>
#include <string>
using namespace std;
CustomerList::CustomerList() {
    head = nullptr;
}

void CustomerList::addCustomer(const Customer &c) {
    Node* newNode = new Node(c);
    newNode->next = head;
    head = newNode;
    cout << "Customer added successfully!\n";
}

void CustomerList::removeCustomer(int id) {
    if (head == nullptr) {
        cout << "No customers to remove.\n";
        return;
    }

    if (head->data.id == id) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Customer removed successfully!\n";
        return;
    }

    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr && current->data.id != id) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Customer not found.\n";
        return;
    }

    previous->next = current->next;
    delete current;
    cout << "Customer removed successfully!\n";
}

void CustomerList::displayCustomers() const {
    if (head == nullptr) {
        cout << "No customers in the system.\n";
        return;
    }

    Node* temp = head;

    while (temp != nullptr) {
        cout << "ID: " << temp->data.id << endl;
        cout << "Name: " << temp->data.name << endl;
        cout << "Email: " << temp->data.email << endl;
        cout << "Phone: " << temp->data.phone << endl;
        cout << "Address: " << temp->data.address << endl;
        cout << "-------------------------\n";

        temp = temp->next;
    }
}
