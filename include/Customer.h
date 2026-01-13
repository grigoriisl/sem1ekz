#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"
#include "PaymentStrategy.h"

class Customer : public User {
private:
    unique_ptr<PaymentStrategy> paymentStrategy;

public:
    Customer(int id, const string& name, const string& email);
    
    void createOrder() override;
    void viewOrderStatus(int orderId) override;
    void cancelOrder(int orderId) override;

    void addToOrder(int orderId, int productId, int quantity);
    void removeFromOrder(int orderId, int productId);
    void makePayment(int orderId);
    void returnOrder(int orderId);
    void setPaymentStrategy(unique_ptr<PaymentStrategy> strategy);
};

#endif