/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:58:36 by jmagand           #+#    #+#             */
/*   Updated: 2026/03/23 17:02:16 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm(target, 145, 127)
{
	std::string filename = target + "_shrubbery";
	
	std::ofstream file(filename.c_str());
	if (!file.fail()) 
		return ;

	file << "    /\\\n";
    file << "   //\\\\\n";
    file << "  ///\\\\\\\n";
    file << " ////\\\\\\\\\n";
    file << "/////\\\\\\\\\\\n";
    file << "     ||\n";
	
	file.close();
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
	: AForm(copy), _target(copy._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
        AForm::operator=(other);
    _target = other._target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	(void)executor;
}
