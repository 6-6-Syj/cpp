/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:49:49 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/12 17:49:47 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() : _type("John") {}

Weapon::Weapon(std::string type)
{
	this->_type = type;
}

Weapon::~Weapon() {}

std::string Weapon::getType() const
{
	return (_type);
}

void Weapon::setType(std::string newType)
{
	_type = newType;
}