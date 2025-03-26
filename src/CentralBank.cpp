#include "CentralBank.h"

CentralBank* CentralBank::instance = nullptr;

CentralBank::CentralBank() {}

CentralBank* CentralBank::getInstance() {
    if (!instance) {
        instance = new CentralBank();
    }
    return instance;
}

void CentralBank::registerBank(Bank* bank) {
    banks.push_back(bank);
}

void CentralBank::processInterbankTransfer(Account* from, Account* to, double amount) {
}
