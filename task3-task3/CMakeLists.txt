cmake_minimum_required(VERSION 3.10)
project(banking_system)

set(CMAKE_CXX_STANDARD 17)

# Исходные файлы
set(SOURCES
    src/Account.cpp
    src/Bank.cpp
    src/CentralBank.cpp
    src/Client.cpp
    src/ConsoleInterface.cpp
    src/CreditAccount.cpp
    src/DepositAccount.cpp
    src/main.cpp
)

# Заголовочные файлы
set(HEADERS
    include/Account.h
    include/Bank.h
    include/CentralBank.h
    include/Client.h
    include/ConsoleInterface.h
    include/DebitAccount.h
    include/DepositAccount.h
    include/exceptions.h

)

add_executable(banking_system ${SOURCES} ${HEADERS})

target_include_directories(banking_system PRIVATE include)