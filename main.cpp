#include <iostream>
#include <vector>

class BankAccount {
public:
    //Default constructor
    BankAccount() {
        accountNumber = "00000";
        accountHolderName = "Unknown";
        balance = 0.0;
    }
    // Parameterized constructor
    BankAccount(std::string Num, std::string Name, double bal ) {
        accountNumber = Num;
        accountHolderName = Name;
        balance = bal;
    }
    //public accessor methods
    std::string GetAccountNum() const { return accountNumber; };
    std::string GetAccountHolderName() const { return accountHolderName; };
    double GetBalance() const { return balance; };
    //public setter method
    void SetAccountHolderName(std::string Name) { accountHolderName = Name; };
    //public member functions
    void Deposit(double amount);
    void Withdraw(double amount);
private:
    std::string accountNumber;
    std::string accountHolderName;
    double balance;
};

void BankAccount::Deposit(double amount) {
    balance += amount;
    std::cout << "---Deposit Successful---" << std::endl;
    std::cout << "Balance: $" << balance << std::endl;
}

void BankAccount::Withdraw(double amount) {
    balance -= amount;
    std::cout << "---Withdrawal Successful---" << std::endl;
    std::cout << "Balance: $" << balance << std::endl;
}

int PrintDisplay() {
    int MenuChoice;
    std::cout << "1. Create New Account" <<std::endl;
    std::cout << "2. Deposit to Account" <<std::endl;
    std::cout << "3. Withdraw from Account" <<std::endl;
    std::cout << "4. Display all Accounts" <<std::endl;
    std::cout << "5. Exit Program" <<std::endl;
    std::cout << "Enter choice (1-5): ";
    std::cin >> MenuChoice;
    while (MenuChoice < 1 || MenuChoice > 5) {
        std::cout << "Invalid Choice, Try again (1-5): " << std::endl;
        std::cin >> MenuChoice;
    }
    return MenuChoice;
}



int main() {
    std::vector<BankAccount> accounts;
    int choice;
    do {
        choice = PrintDisplay();
        switch (choice) {
            //New Account Creation
            case 1:{
                std::string id, name;
                double InitialBal;
                //Account Credentials
                std::cout << "Enter Account ID: " << std::endl; std::cin >> id;
                std::cout << "Enter Account Name: " << std::endl; std::cin.ignore(); std::getline(std::cin, name);
                std::cout << "Enter Initial Balance: " << std::endl; std::cin >> InitialBal;
                //Balance Error Checking
                if (InitialBal < 0) {
                    while (InitialBal < 0) {
                        std::cout << "Invalid Balance (Must be positive): "; std::cin >> InitialBal;
                    }
                }
                accounts.push_back(BankAccount(id, name, InitialBal));
                std::cout << "---Account Successfully Created---" << std::endl;
                break;
            }
            //Deposit to existing account
            case 2: {
                bool AccountFound = false;
                std::string searchID;
                double depositAmount;
                std::cout << "Enter Account ID: "; std::cin >> searchID;
                for (int i = 0; i < accounts.size(); ++i) {
                    //check if account exists
                    if (accounts.at(i).GetAccountNum() == searchID) {
                        std::cout << "Account Found, Enter Deposit Amount: " << std::endl;
                        std::cin >> depositAmount;
                        //ensure deposit is positive
                        if (depositAmount < 0) {
                            while (depositAmount < 0) {
                                std::cout << "Invalid Deposit Amount (must be positive): ";
                                std::cin >> depositAmount;
                            }
                        }
                        accounts.at(i).Deposit(depositAmount);
                        AccountFound = true;
                    }
                }
                if (!AccountFound) {
                    std::cout << "Account Not Found" << std::endl;
                }
                break;
            }
            //Withdraw from existing Account
            case 3: {
                bool AccountFound = false;
                std::string searchID;
                double withdrawAmount;
                std::cout << "Enter Account ID: "; std::cin >> searchID;
                for (int i = 0; i < accounts.size(); ++i) {
                    //find existing account
                    if (accounts.at(i).GetAccountNum() == searchID) {
                        std::cout << "Account Found, Enter Withdraw Amount: " << std::endl;
                        std::cin >> withdrawAmount;
                        //ensure withdrawal is positive
                        if (withdrawAmount < 0) {
                            while (withdrawAmount < 0) {
                                std::cout << "Invalid Withdraw Amount (must be positive): ";
                            }
                        }
                        //ensure withdrawal is less than account balance
                        else if (withdrawAmount > accounts.at(i).GetBalance()) {
                            std::cout << "---Insufficient Funds---" << std::endl;
                        }
                        else {
                            accounts.at(i).Withdraw(withdrawAmount);
                        }
                        AccountFound = true;
                    }
                }
                if (!AccountFound) {
                    std::cout << "Account Not Found" << std::endl;
                }
                break;
            }
            //Display All Accounts
            case 4: {
                std::cout << "--------------------" << std::endl;
                //loop through accounts vector
                for (int i = 0; i < accounts.size(); ++i) {
                    std::cout << "Account " << i + 1 << std::endl;
                    std::cout << "Account Name: " << accounts.at(i).GetAccountHolderName() << std::endl;
                    std::cout << "Account ID: " << accounts.at(i).GetAccountNum() << std::endl;
                    std::cout << "Account Balance: " << accounts.at(i).GetBalance() << std::endl;
                    std::cout << "--------------------" << std::endl;
                }
                break;
            }
            case 5: {
                std::cout << "Thank You For Trying My Program" << std::endl;
            }
        }

    }while (choice != 5);
    return 0;
}