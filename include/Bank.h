#ifndef BANK_H
#define BANK_H

#include <vector>
#include <map>
#include <string>
#include <ctime>

class Client;
class Account;
class CentralBank;
class Transaction;

class Bank {
private:
    std::string id;
    std::string name;
    CentralBank* centralBank;
    std::vector<Client*> clients;
    std::vector<Account*> accounts;

    double creditCommission;
    std::map<double, double> depositRates;

public:
    Bank(const std::string& name, CentralBank* centralBank);

    Client* createClient(const std::string& firstName, const std::string& lastName,
        const std::string& passport = "", const std::string& address = "");

    Account* createDebitAccount(Client* client, double initialBalance);
    Account* createDepositAccount(Client* client, double initialBalance, time_t endDate);
    Account* createCreditAccount(Client* client, double initialBalance, double creditLimit);

    void applyDailyInterest();
    void applyMonthlyCommissions();

    void processTransaction(Transaction* transaction);
    void cancelTransaction(const std::string& transactionId);
};

#endif