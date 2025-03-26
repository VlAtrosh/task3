#ifndef DEBIT_ACCOUNT_H
#define DEBIT_ACCOUNT_H

#include "Account.h"

class DebitAccount : public Account {
private:
    double interestRate;

public:
    DebitAccount(Client* owner, Bank* bank, double initialBalance, double interestRate);

    void deposit(double amount) override;
    void withdraw(double amount) override;
    void transfer(Account* to, double amount) override;
    void applyInterest() override;
    bool canWithdraw(double amount) const override;
};

#endif