#include "DebitAccount.h"
#include "exceptions.h"

DebitAccount::DebitAccount(Client* owner, Bank* bank, double initialBalance, double interestRate)
    : Account(owner, bank, initialBalance), interestRate(interestRate) {
}

void DebitAccount::deposit(double amount) {
    if (amount <= 0) throw InvalidAmountException();
    balance += amount;
}

void DebitAccount::withdraw(double amount) {
    if (!canWithdraw(amount)) throw InsufficientFundsException();
    balance -= amount;
}

bool DebitAccount::canWithdraw(double amount) const {
    return amount > 0 && balance >= amount;
}

void DebitAccount::transfer(Account* to, double amount) {
}

void DebitAccount::applyInterest() {
    balance += balance * interestRate / 365.0;
}