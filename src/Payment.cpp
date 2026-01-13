#include "Payment.h"
#include <iostream>

Payment::Payment(double amount, unique_ptr<PaymentStrategy> strategy)
    : amount(amount), strategy(move(strategy)), paid(false) {
}

void Payment::processPayment() {
    if (strategy) {
        strategy->pay(amount);
        paid = true;
    }
}

string Payment::getPaymentMethod() const {
    if (strategy) return strategy->getName();
    return "None";
}