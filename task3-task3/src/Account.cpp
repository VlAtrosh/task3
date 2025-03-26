#include "Account.h"
#include "Transaction.h"
#include "Client.h"
#include "Bank.h"

Account::Account(Client* owner, Bank* bank, double initialBalance)
    : owner(owner), bank(bank), balance(initialBalance) {
}

Account::~Account() {
    for (auto* transaction : transactions) {
        delete transaction;
    }
}

double Account::getBalance() const {
    return balance;
}

std::string Account::getId() const {
    return id;
}

Client* Account::getOwner() const {
    return owner;
}

void Account::addTransaction(Transaction* transaction) {
    transactions.push_back(transaction);
}

void Account::cancelTransaction(const std::string& transactionId) {
}