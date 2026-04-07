/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:41:56 by jmagand           #+#    #+#             */
/*   Updated: 2026/04/07 15:28:11 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("Useless"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName() const
{
	return _name;
}

const int &Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	if (_grade - 1 >= 1)
		_grade--;
	else
		throw GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
	if (_grade + 1 <= 150)
		_grade++;
	else
		throw GradeTooLowException();
}

void Bureaucrat::signForm(Form &Form)
{
	Form.beSigned(*this);
	std::cout << _name << " signs " << Form.getName() << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high.");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low.");
}

std::ostream &operator<<(std::ostream &out, Bureaucrat &who)
{
	out << who.getName() << ", bureaucrat grade " << who.getGrade() << ".";
	return out;
}
