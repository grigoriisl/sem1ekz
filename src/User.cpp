#include "User.h"
#include "Order.h"

User::User(int id, const string& name, const string& email, const string& role) 
    : userId(id), name(name), email(email), role(role) {
}

void User::addOrder(shared_ptr<Order> order) {
    orders.push_back(order);
}

void User::removeOrder(int orderId) {
    for (auto it = orders.begin(); it != orders.end(); ++it) {
        if ((*it)->getOrderId() == orderId) {
            orders.erase(it);
            break;
        }
    }
}