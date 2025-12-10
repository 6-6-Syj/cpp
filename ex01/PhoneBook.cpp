/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:43:18 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/10 15:23:20 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook() : _count(0), _nextIndex(0) {}

bool PhoneBook::addContact() {
    if (std::cin.eof())
        return (false);
    if (!this->_contacts[this->_nextIndex].setFromInput())
        return (false);
    if (this->_count < 8)
        this->_count++;
    this->_nextIndex = (this->_nextIndex + 1) % 8;
    return (true);
}

bool PhoneBook::searchContact() const {
    if (this->_count == 0) {
        std::cout << "PhoneBook is empty." << std::endl;
        return (true);
    }

    std::cout << std::setw(10) << "Index"     << "|"
              << std::setw(10) << "First name"<< "|"
              << std::setw(10) << "Last name" << "|"
              << std::setw(10) << "Nickname"  << std::endl;

    for (int i = 0; i < this->_count; i++)
        this->_contacts[i].printShort(i);

    std::string line;
    int idx = line[0] - '0';
    
    do {
        std::cout << "Enter index: ";
        if (!std::getline(std::cin, line))
            return (false);
        idx = line[0] - '0';
    } while ((idx < 0 || idx >= this->_count));
    
    this->_contacts[idx].printFull();
    
    return (true);
}
