//
// Created by angel on 4/24/2026.
//
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "BankAccount.h" // Include our custom class header

using namespace std;

// Helper Functions

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int findAccountIndex(const vector<BankAccount>& accounts, const string& targetAccNum) {
    for (size_t i = 0; i < accounts.size(); i++) {
        if (accounts[i].getAccountNumber() == targetAccNum) {
            return i;
        }
    }
    return -1; // Not found
}

int main() {
    vector<BankAccount> accounts;
    int choice = 0;

    do {
        cout << "\n--- Bank Account Management System ---\n";
        cout << "1. Create New Account\n";
        cout << "2. View All Accounts\n";
        cout << "3. Deposit Funds\n";
        cout << "4. Withdraw Funds\n";
        cout << "5. Quit\n";
        cout << "Enter your choice (1-5): ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            clearInput();
            continue;
        }

        switch (choice) {
            case 1: {
                string accNum, accName;
                double initialDep;
                cout << "Enter Account Number: ";
                cin >> accNum;
                cin.ignore(); // clear newline for getline
                cout << "Enter Account Holder Name: ";
                getline(cin, accName);
                cout << "Enter Initial Deposit: $";

                while (!(cin >> initialDep) || initialDep < 0) {
                    cout << "Invalid amount. Enter a positive number: $";
                    clearInput();
                }

                accounts.push_back(BankAccount(accNum, accName, initialDep));
                cout << "Account created successfully!\n";
                break;
            }
            case 2: {
                if (accounts.empty()) {
                    cout << "No accounts exist yet.\n";
                } else {
                    cout << "\n--- All Accounts ---\n";
                    for (const auto& acc : accounts) {
                        cout << "Acc #: " << acc.getAccountNumber()
                             << " | Name: " << acc.getAccountHolderName()
                             << " | Balance: $" << acc.getBalance() << "\n";
                    }
                }
                break;
            }
            case 3:
            case 4: {
                if (accounts.empty()) {
                    cout << "No accounts exist yet to perform transactions.\n";
                    break;
                }

                string searchAcc;
                cout << "Enter Account Number: ";
                cin >> searchAcc;

                int index = findAccountIndex(accounts, searchAcc);
                if (index == -1) {
                    cout << "Account not found.\n";
                } else {
                    double amount;
                    cout << "Enter amount: $";
                    while (!(cin >> amount)) {
                        cout << "Invalid input. Enter a numeric amount: $";
                        clearInput();
                    }

                    if (choice == 3) {
                        accounts[index].deposit(amount);
                    } else {
                        accounts[index].withdraw(amount);
                    }
                }
                break;
            }
            case 5:
                cout << "Exiting system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please select a valid menu option.\n";
        }
    } while (choice != 5);

    return 0;
}