#include "PaymentStrategy.h"
#include <iostream>

void BankCardPayment::pay(double amount) {
    cout << "Paid " << amount << " using Bank Card" << endl;
}

void EWalletPayment::pay(double amount) {
    cout << "Paid " << amount << " using E-Wallet" << endl;
}

void SBPPayment::pay(double amount) {
    cout << "Paid " << amount << " using SBP" << endl;
}