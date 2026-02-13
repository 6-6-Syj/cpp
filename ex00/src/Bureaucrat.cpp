/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:41:56 by jmagand           #+#    #+#             */
/*   Updated: 2026/02/13 16:58:06 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Bob"), _grade(0) {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) 
{
	// try
	// {
	// 	/* do some stuff with bureaucrats */
	// }
	// catch (std::exception & e)
	// {
	// /* handle exception */
	// }
	if (grade < 0 || grade > 150)
		this->_grade = grade;
	else
		// use trycatch ? 
		// either a Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException.
	;
}

	// try
	// {
	// /* do some stuff with bureaucrats */
	// }
	// catch (std::exception & e)
	// {
	// /* handle exception */
	// }

Bureaucrat::~Bureaucrat() {}


const std::string& Bureaucrat::getName()
{
	return this->_name;
}

const int& Bureaucrat::getGrade()
{
	return this->_grade;
}

