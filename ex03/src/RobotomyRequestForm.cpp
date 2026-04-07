/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 16:00:04 by jmagand           #+#    #+#             */
/*   Updated: 2026/04/07 16:57:07 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm(target, 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
	: AForm(copy), _target(copy._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
		AForm::operator=(other);
	_target = other._target;
	return *this;
}

const std::string &RobotomyRequestForm::getTarget() const
{
	return _target;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);

	std::cout << "* drilling noises *" << std::endl;
	if (rand() % 2)
        std::cout << getTarget() << " has been robotomized successfully." << std::endl;
    else
        std::cout << "Robotomy of " << getTarget() << " has failed." << std::endl;
}