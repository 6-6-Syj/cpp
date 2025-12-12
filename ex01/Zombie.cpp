/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:02:19 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/12 15:17:11 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : _name("Bob") {}

Zombie::Zombie(std::string name) {
	this->_name = name;
}

Zombie::~Zombie() {
	std::cout << getName() << " \"died\"" << std::endl;
}

std::string	Zombie::getName() const {
	return (_name);
}

void	Zombie::announce() const {
	std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;	
}