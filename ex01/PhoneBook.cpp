/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:43:18 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/09 17:43:41 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : _count(0), _nextIndex(0) {}

void PhoneBook::addContact() {
    if (std::cin.eof())
        return;
    _contacts[_nextIndex].setFromInput();
    if (_count < 8)
        _count++;
    _nextIndex = (_nextIndex + 1) % 8;
}

void PhoneBook::searchContact() const {
    if (_count == 0) {
        std::cout << "PhoneBook is empty." << std::endl;
        return;
    }

    std::cout << std::setw(10) << "Index"     << "|"
              << std::setw(10) << "First name"<< "|"
              << std::setw(10) << "Last name" << "|"
              << std::setw(10) << "Nickname"  << std::endl;

    for (int i = 0; i < _count; i++)
        _contacts[i].printShort(i);

    std::cout << "Enter index: ";
    std::string line;
    if (!std::getline(std::cin, line) || line.size() != 1 || line[0] < '0' || line[0] > '7') {
        std::cout << "Invalid index." << std::endl;
        return;
    }
    int idx = line[0] - '0';
    if (idx < 0 || idx >= _count) {
        std::cout << "Invalid index." << std::endl;
        return;
    }
    _contacts[idx].printFull();
}
