#ifndef CENTRAL_BANK_H
#define CENTRAL_BANK_H

#include <vector>
#include <string>

class Bank;

class CentralBank {
private:
    static CentralBank* instance;
    std::vector<Bank*> banks;

    CentralBank();

public:
    static CentralBank* getInstance();

    void registerBank(Bank* bank);
    void unregisterBank(Bank* bank);

    void processInterbankTransfer(Account* from, Account* to, double amount);
    void notifyBanksDaily();
    void notifyBanksMonthly();
};

#endif