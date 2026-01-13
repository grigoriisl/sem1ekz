#include "Order.h"
#include <iostream>

Order::Order(int id, int userId) 
    : orderId(id), userId(userId), status("pending"), totalPrice(0.0) {
}

void Order::addItem(int productId, int quantity, double price) {
    auto item = make_unique<OrderItem>(items.size() + 1, productId, quantity, price);
    items.push_back(move(item));
    calculateTotal();
}

void Order::calculateTotal() {
    totalPrice = 0.0;
    for (const auto& item : items) {
        totalPrice += item->getTotalPrice();
    }
}

void Order::updateStatus(const string& newStatus) {
    status = newStatus;
}