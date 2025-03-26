#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>

class Client;
class Bank;
class Transaction;

class Account {
protected:
    double balance;
    Client* owner;
    Bank* bank;
    std::string id;
    std::vector<Transaction*> transactions;

public:
    Account(Client* owner, Bank* bank, double initialBalance);
    virtual ~Account();

    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual void transfer(Account* to, double amount) = 0;
    virtual void applyInterest() = 0;
    virtual bool canWithdraw(double amount) const = 0;

    double getBalance() const;
    std::string getId() const;
    Client* getOwner() const;

    void addTransaction(Transaction* transaction);
    void cancelTransaction(const std::string& transactionId);
};

#endif // ACCOUNT_H