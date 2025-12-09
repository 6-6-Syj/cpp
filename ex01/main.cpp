/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:13:14 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/09 17:51:32 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int main() {
    PhoneBook    phonebook;
    std::string  command;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command))
            break;
        if (command == "ADD")
            phonebook.addContact();
        else if (command == "SEARCH")
            phonebook.searchContact();
        else if (command == "EXIT")
            break;
    }
    return (0);
}

// class Contact {
// 	private:
// 		std::string firstName;
// 		std::string lastName;
// 		std::string nickName;
// 		std::string	phoneNumber;
// 		std::string darkestSecret;
		
// 	public:
// 	// Constructor
// 	Contact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret) {
// 		this->firstName = firstName;
// 		this->lastName = lastName;
// 		this->nickName = nickName;
// 		this->phoneNumber = phoneNumber;
// 		this->darkestSecret = darkestSecret;
// 	}

// 	// Instance method
// 	void displayDetails() {
//         std::cout << "firstname: " << firstName << std::endl;
// 		std::cout << "lastname: " << lastName << std::endl;
//         std::cout << "nickname: " << nickName << std::endl;
// 		std::cout << "phone: " << phoneNumber << std::endl;
//         std::cout << "secret: " << darkestSecret << std::endl;
//     }
// };

// class Phonebook {
// 	private:
// 		Contact arr[7];
// 	public:
// 	// void add() {
		
// 	// };
// 	// std::string search() {
		
// 	// };
// 	// void exit() {
		
// 	// };
// };

// int main(void) {
// 	std::string cmd;

// 	std::cout << "Enter your command (ADD - SEARCH - EXIT): ";
// 	std::cin >> cmd;
	
// 	if (cmd == "ADD") {
// 		std::string firstName;
// 		std::string lastName;
// 		std::string nickName;
// 		std::string phone;
// 		std::string secret;
// 		std::cout << "Enter a firstname: ";
// 		std::cin >> firstName;
// 		std::cout << "Enter a lastname: ";
// 		std::cin >> lastName;
// 		std::cout << "Enter a nickname: ";
// 		std::cin >> nickName;
// 		std::cout << "Enter a phone: ";
// 		std::cin >> phone;
// 		std::cout << "Enter a secret about this person: ";
// 		std::cin >> secret;
// 		Phonebook arr[0](firstName, lastName, nickName, phone, secret);
// 	}
// 	else if (cmd == "SEARCH") {
		
// 	}
// 	else if (cmd == "EXIT") {
		
// 	}
// 	else {
// 		std::cout << "Unknown command" << cmd << std::endl;
// 	}
	
// 	// Contact syj("Jessy", "Magand", "66Syj", "0768166895", "Can't code");
// 	// syj.displayDetails();
	
// 	return (0);
// }