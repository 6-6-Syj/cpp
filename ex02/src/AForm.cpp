/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:55:27 by jmagand           #+#    #+#             */
/*   Updated: 2026/03/23 16:58:37 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, int toSign, int toExecute) : _name(name), _isSigned(false), _toSign(toSign), _toExecute(toExecute) {}

AForm::AForm(const AForm &other) : _name(other._name), _isSigned(other._isSigned) {}

AForm& AForm::operator=(const AForm &other)
{
	if (this != &other)
		this->_isSigned = other._isSigned;
	return *this;
}

AForm::~AForm() {}

const std::string &AForm::getName() const
{
	return _name;
}

const bool &AForm::getIsSigned() const
{
	return _isSigned;
}

const int &AForm::getSignInfo() const
{
	return _toSign;
}

const int &AForm::getExecuteInfo() const
{
	return _toExecute;
}

void AForm::beSigned(Bureaucrat &who)
{
	if (who.getGrade() <= _toSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const
{
	(void)executor;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high.");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low.");
}

std::ostream &operator<<(std::ostream &out, AForm &AForm)
{
	out << AForm.getName() << (AForm.getIsSigned() ? " is signed !" : " isn't signed.") << std::endl;
	return out;
}