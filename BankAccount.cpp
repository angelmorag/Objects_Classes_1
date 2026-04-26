//
// Created by angel on 4/24/2026.
//

#include "BankAccount.h"
#include <iostream>

using namespace std;

// Constructors
BankAccount::BankAccount() : accountNumber("UNKNOWN"), accountHolderName("UNKNOWN"), balance(0.0) {}

BankAccount::BankAccount(string accNum, string accName, double initialBalance) {
    accountNumber = accNum;
    accountHolderName = accName;
    balance = (initialBalance > 0) ? initialBalance : 0.0;
}

// Accessors
string BankAccount::getAccountNumber() const { return accountNumber; }
string BankAccount::getAccountHolderName() const { return accountHolderName; }
double BankAccount::getBalance() const { return balance; }

// Mutators
void BankAccount::setAccountHolderName(string newName) { accountHolderName = newName; }

// Action Methods
void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        cout << "Successfully deposited $" << amount << ".\n";
    } else {
        cout << "Invalid deposit amount. Must be greater than zero.\n";
    }
}

void BankAccount::withdraw(double amount) {
    if (amount > balance) {
        cout << "Insufficient funds! Current balance: $" << balance << "\n";
    } else if (amount <= 0) {
        cout << "Invalid withdrawal amount. Must be greater than zero.\n";
    } else {
        balance -= amount;
        cout << "Successfully withdrew $" << amount << ".\n";
    }
}