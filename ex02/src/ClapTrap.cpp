/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 13:13:16 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/19 19:38:35 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : _name("Bob"), _hp(10), _energy(10), _ad(0)
{
	std::cout << RED "Constructor by default called" RST << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _energy(10), _ad(0)
{
	std::cout << RED "Constructor by name called" RST << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name), _hp(other._hp), _energy(other._energy), _ad(other._ad)
{
	std::cout << RED "Copy constructor called" RST << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << RED "Copy assignment operator called" RST << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hp = other._hp;
		this->_energy = other._energy;
		this->_ad = other._ad;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << RED << this->_name << " died." RST << std::endl;
}

ClapTrap &ClapTrap::operator--()
{
	this->_energy--;
	return *this;
}

std::string ClapTrap::getName()
{
	return this->_name;
}

unsigned int ClapTrap::getHp()
{
	return this->_hp;
}

unsigned int ClapTrap::getEnergy()
{
	return this->_energy;
}

int ClapTrap::getAd()
{
	return this->_ad;
}

void ClapTrap::setAd(int ad)
{
	this->_ad = ad;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_hp <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " can't attack " << target << " 'cause hp: " << this->_hp << std::endl;
		return;
	}
	else if (this->_energy == 0)
	{
		std::cout << "ClapTrap " << this->_name << " can't attack " << target << " 'cause energy: " << this->_energy << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing "
			  << this->_ad << " points of damage!" << std::endl;
	this->_energy--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hp <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is already dead!" << std::endl;
		return;
	}
	if (amount > this->_hp)
	{
		unsigned int actualDamage = this->_hp;
		this->_hp = 0;
		std::cout << "ClapTrap " << this->_name << " lost " << actualDamage << " hit points! (HP: " << this->_hp << "/10)" << std::endl;
	}
	else
	{
		this->_hp -= amount;
		std::cout << "ClapTrap " << this->_name << " lost " << amount << " hit points! (HP: " << this->_hp << "/10)" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hp <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " can't regains 'cause hp: " << this->_hp << std::endl;
		return;
	}
	else if (this->_energy <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " can't regains 'cause energy: " << this->_energy << std::endl;
		return;
	}
	else
	{
		unsigned int healAmount = amount;
		if (healAmount > (10 - this->_hp))
			healAmount = 10 - this->_hp;

		this->_hp += healAmount;
		std::cout << "ClapTrap " << this->_name << " regains " << healAmount
					<< " hit points! (HP: " << this->_hp << "/10)" << std::endl;
	}
	this->_energy--;
}