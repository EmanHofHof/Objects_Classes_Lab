# BankAccount Class
A C++ class for representing an account in a Banking System
## Data Dictionary
| Attribute         | Data Type     | Description                    |
|-------------------|---------------|--------------------------------|
|`accountNumber`    | `std::string` | Bank Account Number.           |
|`accountHolderName`| `std::string` | Bank Account Owner.            |
|`balance`          | `double`      | Bank Account Balance.          |
## Methods List

| Method Signature              | Return Type   | Description                          |
|-------------------------------|---------------|--------------------------------------|
| `BankAccount()`               | (Constructor) | Default constructor.                 |
| `BankAccount(Num, Name, bal)` | (Constructor) | Parameterized constructor.           |
| `getAccountNum() const`       | `std::string` | Gets the Account's ID Number.        |
| `getAccountHolderName() const`| `std::string` | Gets the Account's Account Name.     |
| `getBalance() const`          | `double`      | Gets Account's Balance.              |
| `Deposit()`                   | `void`        | Deposits money into Account Balance. |
| `Withdraw()`                  | `void`        | Withdraws money from Account Balance.|    
