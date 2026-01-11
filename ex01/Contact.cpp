/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:34:23 by jmagand           #+#    #+#             */
/*   Updated: 2026/01/11 12:20:38 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip>

Contact::Contact() {}

static bool setInput(std::string s)
{
    if (s.size() > 0 && s.size() < 1024)
        return (true);
    return (false);
}

bool Contact::setFromInput()
{
    std::string input;

    do
    {
        std::cout << "First name: ";
        if (!std::getline(std::cin, input))
            return (false);
    } while (!setInput(input));
    this->_firstName = input;

    do
    {
        std::cout << "Last name: ";
        if (!std::getline(std::cin, input))
            return (false);
    } while (!setInput(input));
    this->_lastName = input;

    do
    {
        std::cout << "Nickname: ";
        if (!std::getline(std::cin, input))
            return (false);
    } while (!setInput(input));
    this->_nickname = input;

    do
    {
        std::cout << "Phone number: ";
        if (!std::getline(std::cin, input))
            return (false);
    } while (!setInput(input));
    this->_phoneNumber = input;

    do
    {
        std::cout << "Darkest secret: ";
        if (!std::getline(std::cin, input))
            return (false);
    } while (!setInput(input));
    this->_darkestSecret = input;

    return (true);
}

static std::string truncateField(std::string s)
{
    if (s.length() > 10)
        return (s.substr(0, 9) + ".");
    return (s);
}

void Contact::printShort(int index) const
{
    std::cout << std::setw(10) << index << "|"
              << std::setw(10) << truncateField(this->_firstName) << "|"
              << std::setw(10) << truncateField(this->_lastName) << "|"
              << std::setw(10) << truncateField(this->_nickname) << std::endl;
}

void Contact::printFull() const
{
    std::cout << "First name: " << this->_firstName << std::endl;
    std::cout << "Last name: " << this->_lastName << std::endl;
    std::cout << "Nickname: " << this->_nickname << std::endl;
    std::cout << "Phone number: " << this->_phoneNumber << std::endl;
    std::cout << "Darkest secret: " << this->_darkestSecret << std::endl;
}
