#ifndef MANAGER_H
#define MANAGER_H

#include "User.h"

class Manager : public User {
public:
    Manager(int id, const string& name, const string& email);
    
    void createOrder() override;
    void viewOrderStatus(int orderId) override;
    void cancelOrder(int orderId) override;

    void approveOrder(int orderId);
    void updateStock(int productId, int newQuantity);
    void viewPendingOrders();
    void viewApprovedOrdersHistory();
};

#endif