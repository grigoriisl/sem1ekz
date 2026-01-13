#ifndef USER_H
#define USER_H

#include <string>
#include <memory>
#include <vector>

using namespace std;

class Order;

class User {
protected:
    int userId;
    string name;
    string email;
    string role;
    vector<shared_ptr<Order>> orders;

public:
    User(int id, const string& name, const string& email, const string& role);
    virtual ~User() {}

    virtual void createOrder() = 0;
    virtual void viewOrderStatus(int orderId) = 0;
    virtual void cancelOrder(int orderId) = 0;

    int getUserId() const { return userId; }
    string getRole() const { return role; }
    string getName() const { return name; }
    string getEmail() const { return email; }

    void addOrder(shared_ptr<Order> order);
    void removeOrder(int orderId);
    vector<shared_ptr<Order>> getOrders() const { return orders; }
};

#endif