# BankAccount Class

A C++ class for simulating basic banking operations and managing account data within a banking system.

## Data Dictionary

| Attribute           | Data Type     | Description                                      |
|---------------------|---------------|--------------------------------------------------|
| `accountNumber`     | `std::string` | The unique identifier for the bank account.      |
| `accountHolderName` | `std::string` | The full name of the account owner.              |
| `balance`           | `double`      | The current monetary balance in the account.     |

## Methods List

| Method Signature                                            | Return Type   | Description                                            |
|-------------------------------------------------------------|---------------|--------------------------------------------------------|
| `BankAccount()`                                             | (Constructor) | Default constructor initializing empty/zero values.    |
| `BankAccount(accountNumber, accountHolderName, balance)`    | (Constructor) | Parameterized constructor to initialize starting state.|
| `getAccountNumber() const`                                  | `std::string` | Returns the account number.                            |
| `getAccountHolderName() const`                              | `std::string` | Returns the account holder's name.                     |
| `getBalance() const`                                        | `double`      | Returns the current account balance.                   |
| `setAccountHolderName(newName)`                             | `void`        | Updates the account holder's name.                     |
| `deposit(amount)`                                           | `void`        | Adds the specified amount to the account balance.      |
| `withdraw(amount)`                                          | `void`        | Deducts the amount if sufficient funds are available.  |