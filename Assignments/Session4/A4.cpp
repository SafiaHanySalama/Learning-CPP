/**
    * Creating a Bank Account System
    The program should have the following features:
    Each bank account should have the following attributes:
    ● Account number (unique identifier)
    ● Account holder name
    ● Account type (e.g., savings, current)
    ● Account balance
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

class Bank
{
    class BankAccount
    {
    public:
        string accountNumber;
        string accountHolderName;
        string accountType;
        double accountBalance;
    };

    vector<BankAccount> accounts;   // vector to store all the bank accounts
    string bankName;               // name of the bank
    string bankBranch;             // branch of the bank
    string bankIFSC;               // IFSC code of the bank
    public:
    Bank(string name, string branch, string ifsc)
    {
        bankName = name;
        bankBranch = branch;
        bankIFSC = ifsc;
    }

    void addAccount(string accountNumber, string accountHolderName, string accountType, double accountBalance)
    {
        BankAccount account;
        account.accountNumber = accountNumber;
        account.accountHolderName = accountHolderName;
        account.accountType = accountType;
        account.accountBalance = accountBalance;
        accounts.push_back(account);
    }
    void displayAccountDetails(string accountNumber)
    {
        for (int i = 0; i < accounts.size(); i++)
        {
            if (accounts[i].accountNumber == accountNumber)
            {
                cout << "Account Number: " << accounts[i].accountNumber << endl;
                cout << "Account Holder Name: " << accounts[i].accountHolderName << endl;
                cout << "Account Type: " << accounts[i].accountType << endl;
                cout << "Account Balance: " << fixed << setprecision(2) << accounts[i].accountBalance << endl;
                return;
            }
        }
        cout << "Account not found" << endl;
    }
    void displayAllAccounts()
    {
        for (int i = 0; i < accounts.size(); i++)
        {
            cout << "Account Number: " << accounts[i].accountNumber << endl;
            cout << "Account Holder Name: " << accounts[i].accountHolderName << endl;
            cout << "Account Type: " << accounts[i].accountType << endl;
            cout << "Account Balance: " << fixed << setprecision(2) << accounts[i].accountBalance << endl;
            cout << endl;
        }
    }
};
