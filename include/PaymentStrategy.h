#ifndef PAYMENT_STRATEGY_H
#define PAYMENT_STRATEGY_H

#include <string>

using namespace std;

class PaymentStrategy {
public:
    virtual ~PaymentStrategy() {}
    virtual void pay(double amount) = 0;
    virtual string getName() const = 0;
};

class BankCardPayment : public PaymentStrategy {
public:
    void pay(double amount) override;
    string getName() const override { return "Bank Card"; }
};

class EWalletPayment : public PaymentStrategy {
public:
    void pay(double amount) override;
    string getName() const override { return "E-Wallet"; }
};

class SBPPayment : public PaymentStrategy {
public:
    void pay(double amount) override;
    string getName() const override { return "SBP"; }
};

#endif