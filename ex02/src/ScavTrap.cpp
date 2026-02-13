/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 16:33:12 by jmagand           #+#    #+#             */
/*   Updated: 2026/02/13 15:40:41 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_hp = 100;
	this->_energy = 50;
	this->_ad = 20;
	std::cout << BLUE "Constructor by default called " RST << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_name = name;
	this->_hp = 100;
	this->_energy = 50;
	this->_ad = 20;
	std::cout << BLUE "Constructor by name called" RST << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	this->_name = other._name;
	this->_hp = 100;
	this->_energy = 50;
	this->_ad = 20;
	std::cout << BLUE "Copy constructor called" RST << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
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

ScavTrap::~ScavTrap()
{
	std::cout << BLUE << this->_name << " died." RST << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << BLUE "ScavTrap " << this->getName() << " is on Gatekeeper mode!" RST << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->_hp <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " can't attack " << target << " 'cause hp: " << this->_hp << std::endl;
		return;
	}
	else if (this->_energy == 0)
	{
		std::cout << "ScavTrap " << this->_name << " can't attack " << target << " 'cause energy: " << this->_energy << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing "
			  << this->_ad << " points of damage!" << std::endl;
	this->_energy--;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (this->_hp <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " is already dead!" << std::endl;
		return;
	}
	if (amount > this->_hp)
	{
		unsigned int actualDamage = this->_hp;
		this->_hp = 0;
		std::cout << "ScavTrap " << this->_name << " lost " << actualDamage << " hit points! (HP: " << this->_hp << "/100)" << std::endl;
	}
	else
	{
		this->_hp -= amount;
		std::cout << "ScavTrap " << this->_name << " lost " << amount << " hit points! (HP: " << this->_hp << "/100)" << std::endl;
	}
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (this->_hp <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " can't regains 'cause hp: " << this->_hp << std::endl;
		return;
	}
	else if (this->_energy <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " can't regains 'cause energy: " << this->_energy << std::endl;
		return;
	}
	else
	{
		unsigned int healAmount = amount;
		if (healAmount > (100 - this->_hp))
			healAmount = 100 - this->_hp;

		this->_hp += healAmount;
		std::cout << "ScavTrap " << this->_name << " regains " << healAmount
				  << " hit points! (HP: " << this->_hp << "/100)" << std::endl;
	}
	this->_energy--;
}