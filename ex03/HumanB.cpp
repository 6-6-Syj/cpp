/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:49:46 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/12 17:37:55 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB() : _name("John"), _weapon("crude spiked club") {};

HumanB::HumanB(std::string name)
{
	_name = name;
}

HumanB::~HumanB() {}