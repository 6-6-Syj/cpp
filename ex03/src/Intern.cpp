/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 12:40:52 by jmagand           #+#    #+#             */
/*   Updated: 2026/04/07 13:33:18 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern &copy)
{
	(void)copy;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string &name, const std::string &target) const
{
	AForm *form = 0;
	
	if (name == "shrubbery creation")
        form = new ShrubberyCreationForm(target);
    else if (name == "robotomy request")
        form = new RobotomyRequestForm(target);
    else if (name == "presidential pardon")
	{
        form = new PresidentialPardonForm(target);
	}

	if (form != 0)
	{
		std::cout << "Intern creates " << form->getName() << std::endl;
		return form;
	}
	
    std::cout << "Intern cannot create form: " << name << std::endl;
    return 0;
}