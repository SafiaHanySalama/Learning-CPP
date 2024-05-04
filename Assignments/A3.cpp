/**
 * Creating a Bank Account System
The program should have the following features:
Each bank account should have the following attributes:
● Account number (unique identiﬁer)
● Account holder name
● Account type (e.g., savings, current)
● Account balance
Implement the following member functions for the BankAccount
class:
● Constructor to initialize the account attributes
● Deposit function to add funds to the account balance
● Withdraw function to deduct funds from the account balance
● GetAccountNumber function to retrieve the account number
● GetAccountHolder function to retrieve the account holder name
● GetAccountType function to retrieve the account type
● GetAccountBalance function to retrieve the account balance
● DisplayAccountInfo function to display all the account
information
Create a Bank class that manages a collection of BankAccount
objects.
The Bank class should have the following features:
AddAccount function to create and add a new BankAccount to
the collection
GetTotalBalance function to calculate and return the total
balance of all accounts in the bank
DisplayAllAccounts function to display the information of all
accounts in the bank
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BankAccount
{
    int account_number;
    std::string account_holder_name;
    std::string account_type;
    double account_balance;
    public:
    //default constructor
    BankAccount(){
        std::cout << "BankAccount::BankAccount()" << std::endl;
        account_number = 0;
        account_holder_name = "none";
        account_type = "none";
        account_balance = 0.0;
    }
    //parameterized constructor
    BankAccount(int source1,std::string source2,std::string source3,double source4) : account_number{source1}
                                                                                   ,account_holder_name{source2}
                                                                                   ,account_type{source3}
                                                                                   ,account_balance{source4}{
        std::cout << "BankAccount::BankAccount(int,string,string,double)" << std::endl;
    }
    //get the account number
    int get_account_number(void){
        return account_number;
    }
    //get the account holder name
    std::string get_account_holder_name(void){
        return account_holder_name;
    }
    //get the account type
    std::string get_account_type(void){
        return account_type;
    }
    //get the account balance
    double get_account_balance(void){
        return account_balance;
    }
    //deposit funds to the account balance
    void deposit_funds(double source){
        account_balance += source;
    }
    //withdraw funds from the account balance
    void withdraw_funds(double source){
        account_balance -= source;
    }
    //display all the account information
    void display_account_info(void){
        std::cout << "Account number is " << account_number << std::endl;
        std::cout << "Account holder name is " << account_holder_name << std::endl;
        std::cout << "Account type is " << account_type << std::endl;
        std::cout << "Account balance is " << account_balance << std::endl;
    }
};

int main(void)
{
    /*Display Menu 1- add account 2- Deposite funds 3- Withdraw funds 
    4- get total balance 3- display all accounts 4- exit*/
    int choice;
    std::vector<BankAccount> accounts;
    do
    {
        std::cout << "1- Add account" << std::endl;
        std::cout << "2- Deposit funds" << std::endl;
        std::cout << "3- Withdraw funds" << std::endl;
        std::cout << "4- Get total balance" << std::endl;
        std::cout << "5- Display all accounts" << std::endl;
        std::cout << "6- Exit" << std::endl;
        std::cin >> choice;
        switch (choice)
        {
            case 1:
            {
                int account_number;
                std::string account_holder_name;
                std::string account_type;
                double account_balance;
                std::cout << "Enter account number: ";
                std::cin >> account_number;
                std::cout << "Enter account holder name: ";
                std::cin >> account_holder_name;
                std::cout << "Enter account type: ";
                std::cin >> account_type;
                std::cout << "Enter account balance: ";
                std::cin >> account_balance;
                BankAccount account(account_number,account_holder_name,account_type,account_balance);
                accounts.push_back(account);
                std::cout << "Account added successfully" << std::endl;
                break;
            }
            case 2:
            {
                int account_number;
                double amount;
                std::cout << "Enter account number: ";
                std::cin >> account_number;
                std::cout << "Enter amount: ";
                std::cin >> amount;
                for (auto &account : accounts)
                {
                    if (account.get_account_number() == account_number)
                    {
                        account.deposit_funds(amount);
                        break;
                    }
                }
                break;
            }
            case 3:
            {
                int account_number;
                double amount;
                std::cout << "Enter account number: ";
                std::cin >> account_number;
                std::cout << "Enter amount: ";
                std::cin >> amount;
                for (auto &account : accounts)
                {
                    if (account.get_account_number() == account_number)
                    {
                        account.withdraw_funds(amount);
                        break;
                    }
                }
                break;
            }
            case 4:
            {
                double total_balance = 0.0;
                for (auto &account : accounts)
                {
                    total_balance += account.get_account_balance();
                }
                std::cout << "Total balance is " << total_balance << std::endl;
                break;
            }
            case 5:
            {
                std::cout << "Displaying all accounts: " << std::endl;
                for (auto &account : accounts)
                {
                    account.display_account_info();
                }
                break;
            }
            case 6:
            {
                break;
            }
            default:
            {
                std::cout << "Invalid choice" << std::endl;
                break;
            }
        }
    } while (choice != 6);
    return 0;
}