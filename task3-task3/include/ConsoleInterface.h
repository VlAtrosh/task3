#ifndef CONSOLE_INTERFACE_H
#define CONSOLE_INTERFACE_H

#include "Bank.h"
#include <vector>
#include <memory>

class ConsoleInterface {
    std::unique_ptr<Bank> currentBank;
    std::vector<std::unique_ptr<Bank>> banks;
    
    void showMenu(const std::vector<std::string>& options);
    int getChoice(int max);
    
public:
    void run();
    void createBank();
    void selectBank();
    void bankOperations();
    void accountOperations(Client& client);
};
#endif