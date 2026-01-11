/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:49:46 by jmagand           #+#    #+#             */
/*   Updated: 2026/01/11 14:29:48 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB() : _name("John"), _weapon(NULL) {};

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

void HumanB::setWeapon(Weapon &w)
{
	_weapon = &w;
}

void HumanB::attack()
{
	if (!_weapon)
	{
		std::cout << this->_name << " throws a punch" << std::endl;
		return;
	}
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

HumanB::~HumanB() {}