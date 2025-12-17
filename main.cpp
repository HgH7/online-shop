#include <iostream>
#include <string>

#include "./models/customers.h"
#include "./models/products.h"
#include "./models/orders.h"

#include "./DS/cartSystem.h"
#include "./DS/customerAcc.h"
#include "./DS/deliveryqueue.h"
#include "./DS/orderHistory.h"
#include "./DS/products.h"
using namespace std;


void viewProducts()
{









}


















int main()
{
    ProductCatalog catalog;
    catalog.addProduct(1, 10, "Laptop", "Electronics", 15000);
    catalog.addProduct(2, 20, "Phone", "Electronics", 8000);
    catalog.addProduct(3, 15, "Tablet", "Electronics", 6000);
    catalog.addProduct(4, 8, "Smart Watch", "Electronics", 3500);
    catalog.addProduct(5, 25, "Keyboard", "Accessories", 700);
    catalog.addProduct(6, 30, "Mouse", "Accessories", 450);
    catalog.addProduct(7, 12, "Monitor", "Electronics", 4200);
    catalog.addProduct(8, 18, "Printer", "Electronics", 5200);
    catalog.addProduct(9, 40, "USB Flash", "Accessories", 300);
    catalog.addProduct(10, 22, "External HDD", "Accessories", 2800);
    catalog.addProduct(11, 14, "Router", "Networking", 1800);
    catalog.addProduct(12, 9, "Webcam", "Accessories", 950);


    CustomerList ourCustomers;
    ourCustomers.addCustomer(1,"mohsen","fahsgfluywgfuwyg@gmail.com","0114857346576","helwan");
    ourCustomers.addCustomer(3, "Ahmed", "ahmed@gmail.com", "01012345678", "Nasr City");
    ourCustomers.addCustomer(4, "Sara", "sara@gmail.com", "01123456789", "Maadi");
    ourCustomers.addCustomer(5, "Omar", "omar@gmail.com", "01234567890", "Giza");
    ourCustomers.addCustomer(6, "Youssef", "youssef@gmail.com", "01098765432", "Heliopolis");
    ourCustomers.addCustomer(7, "Mona", "mona@gmail.com", "01187654321", "Dokki");
    ourCustomers.addCustomer(8, "Khaled", "khaled@gmail.com", "01256789012", "6 October");
    ourCustomers.addCustomer(9, "Nour", "nour@gmail.com", "01024681357", "Zamalek");
    ourCustomers.addCustomer(10, "Hassan", "hassan@gmail.com", "01136925847", "Shubra");
    ourCustomers.addCustomer(11, "Laila", "laila@gmail.com", "01215975346", "New Cairo");
    ourCustomers.addCustomer(12, "Mahmoud", "mahmoud@gmail.com", "01075395146", "Ain Shams");
    ourCustomers.addCustomer(13,"mohamed","giwejhfuysgfuy@gmail.com","0103465583764","tagmo3");



    OrderHistory history;
   while (true)
   {
       //view products;

       //view cart;

       //profile;

       //exit


   }
    return 0;
}
