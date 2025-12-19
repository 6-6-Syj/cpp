/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 20:32:37 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/19 21:38:00 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
	this->_hp = 100;
	this->_energy = 100;
	this->_ad = 30;
	std::cout << BLUE "Constructor by default called " RST << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_name = name;
	this->_hp = 100;
	this->_energy = 100;
	this->_ad = 30;
	std::cout << BLUE "Constructor by name called" RST << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	this->_name = other._name;
	this->_hp = 100;
	this->_energy = 100;
	this->_ad = 30;
	std::cout << BLUE "Copy constructor called" RST << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << BLUE "Copy assignment operator called" RST << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hp = other._hp;
		this->_energy = other._energy;
		this->_ad = other._ad;
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << BLUE << this->_name << " died." RST << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (this->_hp <= 0)
	{
		std::cout << "FragTrap " << this->_name << " can't attack " << target << " 'cause hp: " << this->_hp << std::endl;
		return;
	}
	else if (this->_energy == 0)
	{
		std::cout << "FragTrap " << this->_name << " can't attack " << target << " 'cause energy: " << this->_energy << std::endl;
		return;
	}
	std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing "
			  << this->_ad << " points of damage!" << std::endl;
	this->_energy--;
}

void FragTrap::takeDamage(unsigned int amount)
{
	if (this->_hp <= 0)
	{
		std::cout << "FragTrap " << this->_name << " is already dead!" << std::endl;
		return;
	}
	if (amount > this->_hp)
	{
		unsigned int actualDamage = this->_hp;
		this->_hp = 0;
		std::cout << "FragTrap " << this->_name << " lost " << actualDamage << " hit points! (HP: " << this->_hp << "/100)" << std::endl;
	}
	else
	{
		this->_hp -= amount;
		std::cout << "FragTrap " << this->_name << " lost " << amount << " hit points! (HP: " << this->_hp << "/100)" << std::endl;
	}
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (this->_hp <= 0)
	{
		std::cout << "FragTrap " << this->_name << " can't regains 'cause hp: " << this->_hp << std::endl;
		return;
	}
	else if (this->_energy <= 0)
	{
		std::cout << "FragTrap " << this->_name << " can't regains 'cause energy: " << this->_energy << std::endl;
		return;
	}
	else
	{
		unsigned int healAmount = amount;
		if (healAmount > (100 - this->_hp))
			healAmount = 100 - this->_hp;

		this->_hp += healAmount;
		std::cout << "FragTrap " << this->_name << " regains " << healAmount
				  << " hit points! (HP: " << this->_hp << "/100)" << std::endl;
	}
	this->_energy--;
}

void FragTrap::highFivesGuys()
{
	std::cout << this->_name << " is aksing for an highfive!" << std::endl;
}