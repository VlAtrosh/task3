#include "ConsoleInterface.h"
#include <iostream>

int main() {
    try {
        ConsoleInterface interface;
        interface.run();
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}