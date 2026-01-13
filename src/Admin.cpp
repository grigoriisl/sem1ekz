#include "Admin.h"
#include <iostream>

Admin::Admin(int id, const string& name, const string& email)
    : User(id, name, email, "admin") {
}

void Admin::createOrder() {
    cout << "Admin creating order..." << endl;
}

void Admin::viewOrderStatus(int orderId) {
    cout << "Admin viewing order status for ID: " << orderId << endl;
}

void Admin::cancelOrder(int orderId) {
    cout << "Admin canceling order ID: " << orderId << endl;
}

void Admin::addProduct(const string& name, double price, int quantity) {
    cout << "Admin adding product: " << name 
              << ", Price: " << price 
              << ", Quantity: " << quantity << endl;
}

void Admin::viewAllOrders() {
    cout << "Admin viewing all orders..." << endl;
}

void Admin::viewAuditLog() {
    cout << "Admin viewing audit log..." << endl;
}

void Admin::generateCSVReport() {
    cout << "Admin generating CSV report..." << endl;
}