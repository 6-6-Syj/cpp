/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:13:14 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/10 13:40:49 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main() {
    PhoneBook    phonebook;
    std::string  command;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command))
            return (0);
        if (command == "ADD") {
            if (!phonebook.addContact())
                break;
        }
        else if (command == "SEARCH") {
            if (!phonebook.searchContact())
                break;
        }
        else if (command == "EXIT")
            break;
    }
    return (0);
}