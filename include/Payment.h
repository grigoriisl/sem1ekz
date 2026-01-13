#ifndef PAYMENT_H
#define PAYMENT_H

#include "PaymentStrategy.h"
#include <memory>

using namespace std;

class Payment {
private:
    double amount;
    unique_ptr<PaymentStrategy> strategy;
    bool paid;

public:
    Payment(double amount, unique_ptr<PaymentStrategy> strategy);
    
    void processPayment();
    bool isPaid() const { return paid; }
    string getPaymentMethod() const;
};

#endif