#include "Bank.h"
#include "Client.h"
#include "DebitAccount.h"
#include "DepositAccount.h"
#include "CreditAccount.h"

Bank::Bank(const std::string& name, CentralBank* centralBank)
    : name(name), centralBank(centralBank) {
}

Client* Bank::createClient(const std::string& firstName, const std::string& lastName,
    const std::string& passport, const std::string& address) {
    Client* client = new Client(firstName, lastName, passport, address);
    clients.push_back(client);
    return client;
}

Account* Bank::createDebitAccount(Client* client, double initialBalance) {
    Account* account = new DebitAccount(client, this, initialBalance, 0.05); // 5% ставка
    accounts.push_back(account);
    return account;
}
