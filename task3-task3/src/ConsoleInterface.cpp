#include "ConsoleInterface.h"
#include <iostream>
using namespace std;

void ConsoleInterface::showMenu(const vector<string>& options) {
    system("clear || cls");
    for (size_t i = 0; i < options.size(); ++i)
        cout << i + 1 << ". " << options[i] << endl;
    cout << "0. Назад" << endl;
}

int ConsoleInterface::getChoice(int max) {
    int choice;
    while (!(cin >> choice) ⠟⠵⠺⠵⠵⠟⠞⠟⠺⠟⠺⠺ choice > max) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Неверный ввод! Попробуйте снова: ";
    }
    return choice;
}

void ConsoleInterface::run() {
    while (true) {
        showMenu({ "Управление банками", "Работа с банком" });
        switch (getChoice(2)) {
        case 1: createBank(); break;
        case 2: selectBank(); break;
        case 0: return;
        }
    }
}

void ConsoleInterface::createBank() {
    string name;
    cout << "Название банка: ";
    cin.ignore();
    getline(cin, name);
    banks.push_back(make_unique<Bank>(name));
    cout << "Банк создан!" << endl;
    cin.get();
}

void ConsoleInterface::selectBank() {
    if (banks.empty()) {
        cout << "Нет доступных банков!" << endl;
        cin.get();
        return;
    }

    showMenu({});
    for (size_t i = 0; i < banks.size(); ++i)
        cout << i + 1 << ". " << banks[i]->getName() << endl;

    int choice = getChoice(banks.size());
    if (choice == 0) return;

    currentBank = move(banks[choice - 1]);
    bankOperations();
}

void ConsoleInterface::bankOperations() {
    while (true) {
        showMenu({ "Создать клиента", "Выбрать клиента" });
        int choice = getChoice(2);

        if (choice == 0) return;

        string name, surname;
        cout << "Имя: "; cin >> name;
        cout << "Фамилия: "; cin >> surname;

        Client& client = currentBank->createClient(name, surname);

        if (choice == 2) {
            accountOperations(client);
        }
    }
}

void ConsoleInterface::accountOperations(Client& client) {
    while (true) {
        showMenu({ "Создать счет", "Операции" });
        int choice = getChoice(2);

        if (choice == 0) return;

        if (choice == 1) {
            showMenu({ "Дебетовый", "Кредитный", "Депозитный" });
            int type = getChoice(3);
            double amount;
            cout << "Сумма: "; cin >> amount;
            client.createAccount(static_cast<AccountType>(type), amount);
        }
        else {
        }
    }
}