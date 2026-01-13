#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"

class Admin : public User {
public:
    Admin(int id, const string& name, const string& email);
    
    void createOrder() override;
    void viewOrderStatus(int orderId) override;
    void cancelOrder(int orderId) override;

    void addProduct(const string& name, double price, int quantity);
    void updateProduct(int productId, double newPrice, int newQuantity);
    void deleteProduct(int productId);
    void viewAllOrders();
    void updateOrderStatus(int orderId, const string& newStatus);
    void viewAuditLog();
    void generateCSVReport();
};

#endif