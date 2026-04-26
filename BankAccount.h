//
// Created by angel on 4/24/2026.
//

#ifndef OBJECTS_CLASSES_1_BANKACCOUNT_H
#define OBJECTS_CLASSES_1_BANKACCOUNT_H

#include <string>

class BankAccount{
private:
    std::string accountNumber;
    std::string accountHolderName;
    double balance;

public:
    // Constructors
    BankAccount();
    BankAccount(std::string accNum, std::string accName, double initialBalance);

    // Accessors
    std::string getAccountNumber() const;
    std::string getAccountHolderName() const;
    double getBalance() const;

    // Mutators
    void setAccountHolderName(std::string newName);

    // Action Methods
    void deposit(double amount);
    void withdraw(double amount);
};


#endif //OBJECTS_CLASSES_1_BANKACCOUNT_H