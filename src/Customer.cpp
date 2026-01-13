#include "Customer.h"
#include <iostream>

Customer::Customer(int id, const string& name, const string& email)
    : User(id, name, email, "customer") {
}

void Customer::createOrder() {
    cout << "Customer creating order..." << endl;
}

void Customer::viewOrderStatus(int orderId) {
    cout << "Customer viewing order status for ID: " << orderId << endl;
}

void Customer::cancelOrder(int orderId) {
    cout << "Customer canceling order ID: " << orderId << endl;
}

void Customer::addToOrder(int orderId, int productId, int quantity) {
    cout << "Customer adding to order: " << orderId << endl;
}

void Customer::removeFromOrder(int orderId, int productId) {
    cout << "Customer removing from order: " << orderId << endl;
}

void Customer::makePayment(int orderId) {
    cout << "Customer making payment for order: " << orderId << endl;
}

void Customer::returnOrder(int orderId) {
    cout << "Customer returning order: " << orderId << endl;
}

void Customer::setPaymentStrategy(unique_ptr<PaymentStrategy> strategy) {
    paymentStrategy = move(strategy);
}