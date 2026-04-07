/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:55:27 by jmagand           #+#    #+#             */
/*   Updated: 2026/04/07 16:20:43 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Unknown"), _isSigned(false), _toSign(100), _toExecute(50) {}

Form::Form(const std::string &name) : _name(name), _isSigned(false), _toSign(100), _toExecute(50) {}

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), _toSign(other._toSign), _toExecute(other._toExecute) {}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return *this;
}

Form::~Form() {}

const std::string &Form::getName() const
{
	return _name;
}

const bool &Form::getIsSigned() const
{
	return _isSigned;
}

const int &Form::getSignInfo() const
{
	return _toSign;
}

const int &Form::getExecuteInfo() const
{
	return _toExecute;
}

void Form::beSigned(Bureaucrat &who)
{
	if (who.getGrade() <= _toSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high.");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low.");
}

std::ostream &operator<<(std::ostream &out, Form &form)
{
	out << form.getName() << (form.getIsSigned() ? " is signed !" : " isn't signed.") << std::endl;
	return out;
}