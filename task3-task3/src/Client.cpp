#include <iostream>

class Client {
private:
	std::string name;
	std::string surname;
	std::string passport;
	std::string address;

public:
	Client(std::string name, std::string surname, std::string passport = "", std::string address = "")
		: name(name), surname(surname), passport(passport), address(address) {
	}
	std::string getName() const {
		return name;
	}
	std::string getSurname() const {
		return surname;
	}
	std::string getPassport() const {
		return passport;
	}
	std::string getaddress() const {
		return address;
	}
};

