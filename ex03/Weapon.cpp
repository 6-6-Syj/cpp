/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:49:49 by jmagand           #+#    #+#             */
/*   Updated: 2026/02/09 13:52:26 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() : _type("John") {}

Weapon::Weapon(std::string type)
{
	this->_type = type;
}

Weapon::~Weapon() {}

const std::string& Weapon::getType() const
{
	return (_type);
}

void Weapon::setType(std::string newType)
{
	_type = newType;
}