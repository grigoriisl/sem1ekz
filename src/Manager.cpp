#include "Manager.h"
#include <iostream>

Manager::Manager(int id, const string& name, const string& email)
    : User(id, name, email, "manager") {
}

void Manager::createOrder() {
    cout << "Manager creating order..." << endl;
}

void Manager::viewOrderStatus(int orderId) {
    cout << "Manager viewing order status for ID: " << orderId << endl;
}

void Manager::cancelOrder(int orderId) {
    cout << "Manager canceling order ID: " << orderId << endl;
}

void Manager::approveOrder(int orderId) {
    cout << "Manager approving order ID: " << orderId << endl;
}

void Manager::updateStock(int productId, int newQuantity) {
    cout << "Manager updating stock for product ID: " << productId << endl;
}

void Manager::viewPendingOrders() {
    cout << "Manager viewing pending orders..." << endl;
}

void Manager::viewApprovedOrdersHistory() {
    cout << "Manager viewing approved orders history..." << endl;
}