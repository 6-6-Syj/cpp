#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact() {}

bool setInput(std::string s) {
    return (s.size());
}

void Contact::setFromInput() {
    std::string input;
    
    do {
        std::cout << "First name: ";
        std::getline(std::cin, input);
    } while (!setInput(input));
    this->_firstName = input;
    
    do {
        std::cout << "Last name: ";
        std::getline(std::cin, input);
    } while (!setInput(input));
    this->_lastName = input;
    
    do {
        std::cout << "Nickname: ";
        std::getline(std::cin, input);
    } while (!setInput(input));
    this->_nickname = input;
    
    do {
        std::cout << "Phone number: ";
        std::getline(std::cin, input);
    } while (!setInput(input));
    this->_phoneNumber = input;
    
    do {
        std::cout << "Darkest secret: ";
        std::getline(std::cin, input);
    } while (!setInput(input));
    this->_darkestSecret = input;
}

static std::string truncateField(std::string s) {
    if (s.length() > 10)
        return (s.substr(0, 9) + ".");
    return (s);
}

void Contact::printShort(int index) const {
    std::cout << std::setw(10) << index << "|"
              << std::setw(10) << truncateField(this->_firstName) << "|"
              << std::setw(10) << truncateField(this->_lastName)  << "|"
              << std::setw(10) << truncateField(this->_nickname)  << std::endl;
}

void Contact::printFull() const {
    std::cout << "First name: "    << this->_firstName    << std::endl;
    std::cout << "Last name: "     << this->_lastName     << std::endl;
    std::cout << "Nickname: "      << this->_nickname     << std::endl;
    std::cout << "Phone number: "  << this->_phoneNumber  << std::endl;
    std::cout << "Darkest secret: "<< this->_darkestSecret<< std::endl;
}
