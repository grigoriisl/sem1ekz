#ifndef ORDER_H
#define ORDER_H

#include <memory>
#include <vector>
#include <string>
#include "OrderItem.h"

using namespace std;

class Order {
private:
    int orderId;
    int userId;
    string status;
    double totalPrice;
    vector<unique_ptr<OrderItem>> items;

public:
    Order(int id, int userId);
    
    void addItem(int productId, int quantity, double price);
    void removeItem(int productId);
    void calculateTotal();
    void updateStatus(const string& newStatus);
    
    int getOrderId() const { return orderId; }
    int getUserId() const { return userId; }
    string getStatus() const { return status; }
    double getTotalPrice() const { return totalPrice; }
    
    vector<unique_ptr<OrderItem>>& getItems() { return items; }
};

#endif