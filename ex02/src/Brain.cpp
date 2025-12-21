/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 00:21:16 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/22 00:30:26 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "BRAIN: Created" << std::endl;
	for (int i = 0; i < MAX_IDEAS; i++)
		this->_ideas[i] = "";
};

Brain::Brain(const Brain &other)
{
	std::cout << "BRAIN: Copy constructor called" << std::endl;
	for (int i = 0; i < MAX_IDEAS; i++)
		this->_ideas[i] = other._ideas[i];
};

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "BRAIN: Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < MAX_IDEAS; i++)
			this->_ideas[i] = other._ideas[i];
	}
	return *this;
};

Brain::~Brain()
{
	std::cout << "BRAIN: Destroyed" << std::endl;
};

std::string Brain::getIdea(int i) const
{
	if (i < 0 || i >= MAX_IDEAS)
	{
		std::cerr << "Warning: Brain::getIdea index " << i << " out of bounds" << std::endl;
        return "";
	}
	return this->_ideas[i];
}

void Brain::setIdea(int i, std::string idea)
{
	this->_ideas[i] = idea;
}

